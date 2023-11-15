#include "randomwall.h"

int RandomWallXOY::bczfind(int x)
{
    if(x != arr[x]){
        arr[x]=bczfind(arr[x]);
    }
	return arr[x];
}

bool RandomWallXOY::bczmerge(int x, int y)
{
	x=bczfind(x), y=bczfind(y);
	if (x != y) {
		arr[x] = y; //x->y
		return true; //二元块不在和一个集合里
	}
	return false;    //二元块在和一个集合里
}

void RandomWallXOY::genWall()
{
	srand(time(NULL));
	int numX = MAPSIZE, numY = MAPSIZE;

    //初始化并查集
    for (int i = 0 ; i < numX * numY; i++ ) {
		arr[i] = i;
	}

	for (int i = 1; i < numX; i++ ) {
		for (int j = 0 ; j < numY; j++ ) {
			//生成列二元块
			VChunk.push_back({i*numY+j, (i-1)*numY+j, abs(rand())%RAMDOMNESS});
		}
	}

	for (int i = 0 ; i < numX; i++ ) {
		for (int j = 1; j < numY; j++ ) {
            //生成行二元块
			VChunk.push_back({i*numY+j, i*numY+(j-1), abs(rand())%RAMDOMNESS});
		}
	}
	sort(VChunk.begin(), VChunk.end());

	for (auto i: VChunk) {
		if (bczmerge(i.v1, i.v2))
			DrawChunk.push_back(i);
	}

    //生成线的链接关系
	for (auto p: DrawChunk)
	{
		int y1 = p.v1/numY, x1 = p.v1%numY; //前行 后列
		int y2 = p.v2/numY, x2 = p.v2%numY;
        VLine.push_back(
            Line(
                Point2d(x1*P2PDistance + PointCenterDistance, y1*P2PDistance + PointCenterDistance),
                Point2d(x2*P2PDistance + PointCenterDistance, y2*P2PDistance + PointCenterDistance)
            )
        );
	}
    //生成在xoy平面上的点信息
    for (auto p: VLine)
	{
        //选取靠近原点0,0的点
        if(p.p1.x != p.p2.x){
            if(p.p1.x > p.p2.x){
                VWall.push_back(WallXOZ(p.p1,p.p2));
            }
            else{
                VWall.push_back(WallXOZ(p.p2,p.p1));
            }
        }
        else{
            if(p.p1.y > p.p2.y){
                VWall.push_back(WallXOZ(p.p1,p.p2));
            }
            else{
                VWall.push_back(WallXOZ(p.p2,p.p1));
            }
        }
	}
}

void RandomWallXOY::adjectWallPos(){
    for(auto& i : VWall){
        i.DrawX += SaveEdge;
        i.DrawY += SaveEdge;
    }
}