#include "stdafx.h"
#include "PlayerObject.h"
#include <Windows.h>
#include "wtypes.h"
#include <iostream>
//using namespace std;




PlayerObject::PlayerObject()
{
	Health = 100;

}

PlayerObject::PlayerObject(glm::vec3 StartingLocation, glm::vec3 StartingLookAt, glm::vec3 StartingUpVector)
{
	//1280 960

	screenwidth = 0;
	screenheight = 0;
	screenwidth = GetSystemMetrics(SM_CXSCREEN);
	screenheight = GetSystemMetrics(SM_CYSCREEN);
	
	windowx = (screenwidth/2) - 300 - 5;
	windowy = (screenheight/2)-30;
	xorigin = windowx;
	yorigin = windowx;
	 cout << windowx << '\n' << windowy << '\n';


	ShowCursor(false); 
	ShowCursor(false); 
	
	SetCursorPos(960, 540);
		
	angle = 0;
	yangle = 1.4;
	//xorigin= 0;
	//yorigin = 0;
	lx = 0;
	lz= -1;
	ly = 0;
	Position = StartingLocation;
	LookAtLocation = StartingLookAt;
	UpVector = StartingUpVector;
	cbCollisionObject = new CollisionBody(Position, 1);
	//CollisionBody* cbCollisionObject;

}

void PlayerObject::Jump()
{
	//cout<<"JUMP";
	if((cbCollisionObject->ReturnYVelocity() <=0)&&(cbCollisionObject->ReturnYVelocity()>-0.000000001))
	{
	cbCollisionObject->ApplyForce(0,15,0);
	}
}

void PlayerObject::StopPlayer()
{
	
		cbCollisionObject->SetVelocityGravity(0,0);
		
}

void PlayerObject::MouseMove(int x, int y)
{
	//SetVectors();
	//cout<<"x ="<<x<<"\n"<<"y = "<<y<<"\n";
	bool thing = false;
	if(y<80)
	{
		SetCursorPos(screenwidth/2, screenheight/2);
		xorigin = windowx;
		yorigin = windowy;
		thing = true;
	
	}
	else if(y>880)
	{
		SetCursorPos(screenwidth/2, screenheight/2);
		xorigin = windowx;
		yorigin = windowy;
		thing = true;
		//yangle = 2.8;
		
	}
	if(x<100)
	{
		SetCursorPos(screenwidth/2, screenheight/2);
		xorigin = windowx;
		yorigin = windowy;
		thing = true;
	}
	else if(x>1200)
	{
		SetCursorPos(screenwidth/2, screenheight/2);
		xorigin = windowx;
		yorigin = windowy;
		thing = true;
	}

	if(thing == false)
	{

	if(y<=yorigin)
	{
	//cout<<"UP \n";
	if(yangle + 0.001<2.8)
	{
	yangle += 0.001f*-(y-yorigin);
	//cout<<yangle<<"\n";
	}
	ly = -cos(yangle);
	
	}
	else if(y > yorigin)
	{
	//cout<<"DOWN \n ";
	if(yangle -0.001f > 0)
	{
	
	yangle -= 0.001f*(y-yorigin);
	//cout<<yangle<<"\n";
	ly = -cos(yangle);
	}
	}

	if((x>xorigin))
	{
	angle += 0.001f*(x-xorigin);
	lx = sin(angle);
	lz = -cos(angle);
	}
	else if(x < xorigin)
	{
	angle -= 0.001f*-(x-xorigin);
	lx = sin(angle);
	lz = -cos(angle);
	
	}
	xorigin = x;
	yorigin = y;
	}
	
	//lx = sin(angle + ((x - xorigin) * 0.001f));
	//lz = -cos(angle + ((x - xorigin) * 0.001f));
	//angle += ((x - xorigin) * 0.001f);
	
	//angle += ((x - xorigin) * 0.001f);
}

void PlayerObject::MovePlayer(int Direction)
{
	//cbCollisionObject->SetVelocity(2,0,0);
	//SetVectors();
	float speed = 1;
	switch (Direction)
	{
	case 1: 
		{
		//cout << "Forward";
		cbCollisionObject->SetVelocityGravity(ForwardVector.x*speed,ForwardVector.y*speed);
		//cbCollisionObject->SetVelocity(0,0,-5);
		break;
		}
	case 2:
		{
		//cout <<"Back";
		cbCollisionObject->SetVelocityGravity(ForwardVector.x*-1*speed,ForwardVector.y*-1*speed);
		//cbCollisionObject->SetVelocity(0,0,5);
		break;
		}
	case 3:
		{
		//cout <<"Left";
		cbCollisionObject->SetVelocityGravity(SidewaysVector.x*speed,SidewaysVector.y*-1*speed);
		//cbCollisionObject->SetVelocity(-5,0,0);
		//cbCollisionObject->SetVelocity(SidewaysVector.x*speed,SidewaysVector.y*speed,SidewaysVector.z*speed);
		break;
		}
	case 4:
		{
		//cout <<"Right";
		cbCollisionObject->SetVelocityGravity(SidewaysVector.x*-1*speed,SidewaysVector.y*speed);
		//cbCollisionObject->SetVelocity(5,0,0);
		//cbCollisionObject->SetVelocity(SidewaysVector.x*-1*speed,SidewaysVector.y*speed,SidewaysVector.z*-1*speed);
		break;
		}
	case 5:
		{
		//	cout<<"diag--right \n";
		cbCollisionObject->SetVelocityGravity(DiagonalForwardRightVector.x*speed,DiagonalForwardRightVector.y*speed);
		break;
		}
	case 6:
		{
		//	cout<<"diag--left \n ";
		cbCollisionObject->SetVelocityGravity(DiagonalForwardLeftVector.x*speed,DiagonalForwardLeftVector.y*speed);
		break;
		}
	case 7:
		{
		//	cout<<"diag--back--right \n";
			cbCollisionObject->SetVelocityGravity(DiagonalForwardLeftVector.x*speed*-1,DiagonalForwardLeftVector.y*speed*-1);
		break;
		}
	case 8:
		{
		//	cout<<"diag--Back--left \n";
			cbCollisionObject->SetVelocityGravity(DiagonalForwardRightVector.x*speed*-1,DiagonalForwardRightVector.y*speed*-1);
		break;
		}
	default: cout<<"No Direction";
		break;
	}

}

void PlayerObject::SetVectors()
{
	SidewaysVector.x = LookAtLocation.x - Position.x;  
	SidewaysVector.y = LookAtLocation.z - Position.z;  
	glm::vec2 swap;
	swap.x = SidewaysVector.y;
	swap.y = SidewaysVector.x;
	SidewaysVector = swap;
	float magnitude = sqrt(SidewaysVector.x*SidewaysVector.x+SidewaysVector.y*SidewaysVector.y);
	SidewaysVector.x = SidewaysVector.x/magnitude;
	SidewaysVector.y = SidewaysVector.y/magnitude;//SidewaysVector.y/magnitude;
	
	ForwardVector.x = LookAtLocation.x - Position.x;
	ForwardVector.y = LookAtLocation.z - Position.z;
	magnitude = sqrt(ForwardVector.x*ForwardVector.x+ForwardVector.y*ForwardVector.y);
	ForwardVector.x = ForwardVector.x/magnitude;
	ForwardVector.y = ForwardVector.y/magnitude;

	DiagonalForwardRightVector.x = ForwardVector.x + SidewaysVector.x*-1; 
	DiagonalForwardRightVector.y = ForwardVector.y + SidewaysVector.y;

	magnitude = sqrt(DiagonalForwardRightVector.x*DiagonalForwardRightVector.x+DiagonalForwardRightVector.y*DiagonalForwardRightVector.y);
	DiagonalForwardRightVector.x = DiagonalForwardRightVector.x/magnitude;
	DiagonalForwardRightVector.y = DiagonalForwardRightVector.y/magnitude;

	DiagonalForwardLeftVector.x = ForwardVector.x + SidewaysVector.x; 
	DiagonalForwardLeftVector.y = ForwardVector.y + SidewaysVector.y*-1;

	magnitude = sqrt(DiagonalForwardLeftVector.x*DiagonalForwardLeftVector.x+DiagonalForwardLeftVector.y*DiagonalForwardLeftVector.y);
	DiagonalForwardLeftVector.x = DiagonalForwardLeftVector.x/magnitude;
	DiagonalForwardLeftVector.y = DiagonalForwardLeftVector.y/magnitude;
}
void PlayerObject::RotateRight()
{
	angle += 0.1f;
	lx = sin(angle);
	lz = -cos(angle);
}

void PlayerObject::RotateLeft()
{
	angle -= 0.1f;
	lx = sin(angle);
	lz = -cos(angle);
}

glm::vec3 PlayerObject::GetLookAt()
{
	return glm::vec3(Position.x+lx,Position.y+ly,Position.z+lz);
}

glm::vec3 PlayerObject::GetUpVector()
{
	return UpVector;
}

void PlayerObject::Update()
{
	cbCollisionObject->Update();
	Position = cbCollisionObject->GetPosition();
	LookAtLocation = glm::vec3(Position.x+lx,Position.y+ly,Position.z+lz);
	UpVector = glm::vec3(0,1,0);
	SetVectors();
	//cout<<Position.x<<" ----   "<<Position.y<<"----  "<<Position.z<<"\n";

}