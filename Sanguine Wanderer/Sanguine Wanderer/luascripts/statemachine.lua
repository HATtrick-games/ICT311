temp = os.clock()
print("script loaded")
totalTime = 0

-------------------------------------------------------------------------------
-- the global state
-------------------------------------------------------------------------------
state_global = {}

state_global["enter"] = function (player)
	print("Global enter")
end

state_global["execute"] = function(player)
	--print("global execute")
end
  
state_global["exit"] = function(player)

end

state_global["onMessage"] = function(player,msg)
	--print("message recieved1")
end

-------------------------------------------------------------------------------
-- the idle state
-------------------------------------------------------------------------------
state_idle = {}

state_idle["enter"] = function (player)
	
end

state_idle["execute"] = function(player)
	--print("idle execute")
	--player:SetVelocity(Vector2D(0,10))
	player:Wander()

	if player:CanViewTarget() then
		--print("send msg")
		player:SendMessage(0, player:GetPlayerID(), 0, 1, nil)
	end
end

  
state_idle["exit"] = function(player)

end

state_idle["onMessage"] = function(player,msg)
	if(msg.message == 1) then
		--print("msg rec")
		player:GetFSM():ChangeState(state_chase)
	end
end

-------------------------------------------------------------------------------
-- the chase state
-------------------------------------------------------------------------------
state_chase = {}

state_chase["enter"] = function(player)
	--player:SetVelocity(Vector2D(10,0))
	totalTime = 0
end

state_chase["execute"] = function(player)
	--print("chase execute")
	player:PursueTarget()

	totalTime = totalTime + temp
	--print(totalTime)

	if totalTime > 5 then
		player:GetFSM():ChangeState(state_idle)
	end
end
  
state_chase["exit"] = function(player)

end

state_chase["onMessage"] = function(player,msg)

end