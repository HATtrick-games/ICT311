-- intial mouse position
x = 0
y = 0

-- set up inputs
SetKey("moveleft", 97)
SetKey("moveright", 100)
SetKey("moveforward", 119)
SetKey("movebackward", 115)
SetKey("manual", 109)
SetKey("terrainwireframe", 107)
SetKey("quit", 120)

-- load in assets
function LoadResources()
	print("[LUA] LoadResources")
	-- AddAsset("boxbox.obj", "MESH")
end

-- create game objects
function Initialise()
	print("[LUA] Initialise")

	pl = PlayerObject()
	pl:SetPosition(0, 0, 0)
	-- pl:SetAsset("boxbox.obj")
	
end

-- update game logic
function Update(time)
	-- print("[LUA] Update "..time)
	if GetKey("moveright") then
		print("right")
	end

	if GetKey("moveleft") then
		print("left")
	end

	if GetKey("moveforward") then
		print("forward")
	end

	if GetKey("movebackward") then
		print("backward")
	end
end