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
	AddAsset("boxbox.obj", "MESH")
end

-- create game objects
function Initialise()
	print("[LUA] Initialise")
	x = GetMouseX()
	y = GetMouseY()
end

-- update game logic
function Update(time)
	-- print("[LUA] Update "..time)
	if GetKey("moveright") then
		SetPlayerVelocity(1, 0)
	end

	if GetKey("moveleft") then
		SetPlayerVelocity(-1, 0)
	end

	if GetKey("moveforward") then
		SetPlayerVelocity(0, -1)
	end

	if GetKey("movebackward") then
		SetPlayerVelocity(0, 1)
	end

	if x > GetMouseX() then
		RotateCamera(2)
	end

	if x < GetMouseX() then
		RotateCamera(-2)
	end


	x = GetMouseX()
	y = GetMouseY()
end