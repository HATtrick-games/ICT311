 void HeightMap::ComputeFloats()
{

 std::cout << "test";
int total = ((w-1)*2)*(h-1);
Map = new float[total*3];
std::cout << total *3;
std::getchar();
int i = 0;
for(int y = 0; y < h; y++)
{
for(int x = 0; x < (w-1); x++)
{
Map[i] = pHeights[y][x];
Map[i+1] = pHeights[y][(x+1)];
Map[i+2] = pHeights[y+1][x];
Map[i+3] = pHeights[y][x];
Map[i+4] = pHeights[y][(x+1)];
Map[i+5] = pHeights[y+1][(x+1)];
i+=6;
std::cout << x << std::endl;
}
std::cout << "Y:" << y << std::endl;
}
std::cout << "HELLO?!";
}