-- set up inputs
SetKey("attack", 27)


-- load in assets
function LoadResources()
	print("LoadResources")
	AddAsset("boxbox.obj", "MESH")
end

-- create game objects
function Initialise()
	print("Initialise")
end

-- update game logic
function Update(time)
	print("Update"..time)
end