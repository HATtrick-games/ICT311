-- set up inputs
SetKey("moveleft", 1)
SetKey("moveright", 2)
SetKey("moveforward", 3)
SetKey("movebackward", 4)
SetKey("manual", 5)
SetKey("terrainwireframe", 6)
SetKey("quit", 7)

-- load in assets
function LoadResources()
	print("[LUA] LoadResources")
	AddAsset("boxbox.obj", "MESH")
end

-- create game objects
function Initialise()
	print("[LUA] Initialise")
	pl = PlayerObject()
	pl:SetPosition(0, 0, 0)
	pl:SetAsset("boxbox.obj")
	
end

-- update game logic
function Update(time)
	print("[LUA] Update "..time)
end