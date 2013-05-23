#include "StdAfx.h"
#include "AIObject.h"


void AIObject::InitialiseCollisionBody()
{
	MeshCenter.x = (((ObjectMesh->GetMaxX()-ObjectMesh->GetMinX())/2)+ObjectMesh->GetMinX());
	MeshCenter.y = (((ObjectMesh->GetMaxY()-ObjectMesh->GetMinY())/2)+ObjectMesh->GetMinY());
	MeshCenter.z = (((ObjectMesh->GetMaxZ()-ObjectMesh->GetMinZ())/2)+ObjectMesh->GetMinZ());


	MeshCenter.x = MeshCenter.x*Scale.x;
	MeshCenter.y = MeshCenter.y*Scale.y;
	MeshCenter.z = MeshCenter.z*Scale.z;
	MeshCenter.x += Position.x;
	MeshCenter.y += Position.y;
	MeshCenter.z += Position.z;

	cout<<"\n  DISTANCES=="<<((ObjectMesh->GetMaxX()-ObjectMesh->GetMinX())*Scale.x)<<"=="<<((ObjectMesh->GetMaxY()-ObjectMesh->GetMinY())*Scale.y)<<"=="<<((ObjectMesh->GetMaxZ()-ObjectMesh->GetMinZ())*Scale.z)<<"\n";
	cout<<"  \n  MeshCenter"<<MeshCenter.x<<"--/"<<MeshCenter.y<<"--/"<<MeshCenter.z<<"\n";
	cbCollisionObject = new CollisionBody(MeshCenter,((ObjectMesh->GetMaxX()-ObjectMesh->GetMinX())*Scale.x)/2,2/*((ObjectMesh->GetMaxY()-ObjectMesh->GetMinY())*Scale.y)/2*/,((ObjectMesh->GetMaxZ()-ObjectMesh->GetMinZ())*Scale.z)/2, "move");
	//cbCollisionObject->Rotate(180);
}

AIObject::AIObject(void)
{
	aiFSM = new StateMachine<AIObject>(this);
	Position = glm::vec3();
	Velocity = glm::vec3();
	aiTimeElapsed = 0;
	ID = 0;
	target = NULL;
}

AIObject::AIObject(Vector2D pos, Vector2D vel, int id)
{
	//SetPosition(pos.ToGLM());
//	SetVelocity(glm::vec2(vel.x, vel.y));
	ID = id;
	aiFSM = new StateMachine<AIObject>(this);
	aiTimeElapsed = 0.0f;
	target = NULL;
}

AIObject::~AIObject()
{
	delete aiFSM;
}

void AIObject::UpdateAI(float timeElapsed)
{
	
	aiTimeElapsed = timeElapsed;

	//std::cout << GetPosition().x << " " << GetPosition().z << std::endl;
//	Position = cbCollisionObject->GetPosition();

	aiFSM->Update();
}

void AIObject::SendMessage(double delay, int sender, int receiver, int msg, luabind::object extraInfo)
{
	(*MessageDispatcher::GetInstance())->DispatchMessage(delay, sender, receiver, msg, extraInfo);
}

void AIObject::PursueTarget()
{
	if(target != NULL)
	{
		Vector2D pos(Position);
		Vector2D vel(Velocity);

		movementFunctions.PursueTarget(pos, vel, Vector2D(target->GetPosition()), Vector2D(target->GetVelocity()), aiTimeElapsed);

		//this->SetPosition(pos.ToGLM());
	//	this->SetVelocity(glm::vec2(vel.x, vel.y));
	}
}

void AIObject::FleeTarget()
{
	if(target != NULL)
	{
		Vector2D pos(Position);
		Vector2D vel(Velocity);

		movementFunctions.FleeTarget(pos, vel, Vector2D(target->GetPosition()), Vector2D(target->GetVelocity()), Velocity.length(), 10 / (Velocity.length() + 1), aiTimeElapsed);

	//	this->SetPosition(pos.ToGLM());
	//	this->SetVelocity(glm::vec2(vel.x, vel.y));
	}
}

void AIObject::EvadeTarget()
{
	if(target != NULL)
	{
		Vector2D pos(Position);
		Vector2D vel(Velocity);

		movementFunctions.EvadeTarget(pos, pos, Vector2D(target->GetPosition()), Vector2D(target->GetVelocity()), aiTimeElapsed);

	//	this->SetPosition(pos.ToGLM());
	//	this->SetVelocity(glm::vec2(vel.x, vel.y));
	}
}

void AIObject::Wander()
{
	movementFunctions.SetWander(50, 50, 50);

	Vector2D pos(Position);
	Vector2D vel(Velocity);

	movementFunctions.Wander(pos, vel, aiTimeElapsed);

	//this->SetPosition(pos.ToGLM());
	//this->SetVelocity(glm::vec2(vel.x, vel.y));
}

bool AIObject::CanViewTarget()
{
	return movementFunctions.CanSeeTarget(Vector2D(Position), Vector2D(Velocity), Vector2D(target->GetPosition()), 100000000000, 60);
}