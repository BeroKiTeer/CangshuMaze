#include "sky.h"
SkyBox::SkyBox(){
    Distance = 40.0;
    for(int i = 0; i < 6; i++){
        Surface[i] = 0;
    }
    //Top
    SkyBoxPoint.push_back(Point(-Distance, Distance, -Distance));
    SkyBoxPoint.push_back(Point(Distance, Distance, -Distance));
    SkyBoxPoint.push_back(Point(Distance, -Distance, -Distance));
    SkyBoxPoint.push_back(Point(-Distance, -Distance, -Distance));
    
    // //down
    SkyBoxPoint.push_back(Point(-Distance, Distance, Distance));
    SkyBoxPoint.push_back(Point(-Distance, -Distance, Distance));
    SkyBoxPoint.push_back(Point(Distance, -Distance, Distance));
    SkyBoxPoint.push_back(Point(Distance, Distance, Distance));
    //front
    SkyBoxPoint.push_back(Point(Distance,Distance,Distance));
    SkyBoxPoint.push_back(Point(Distance,Distance,-Distance));
    SkyBoxPoint.push_back(Point(-Distance, Distance, -Distance));
    SkyBoxPoint.push_back(Point(-Distance, Distance, Distance));
    //left
    SkyBoxPoint.push_back(Point(Distance, -Distance, Distance));
    SkyBoxPoint.push_back(Point(Distance, -Distance, -Distance));
    SkyBoxPoint.push_back(Point(Distance, Distance, -Distance));
    SkyBoxPoint.push_back(Point(Distance, Distance, Distance));
    //right
    SkyBoxPoint.push_back(Point(-Distance, Distance, Distance));
    SkyBoxPoint.push_back(Point(-Distance, Distance, -Distance));
    SkyBoxPoint.push_back(Point(-Distance, -Distance, -Distance));
    SkyBoxPoint.push_back(Point(-Distance, -Distance, Distance));
    //back
    SkyBoxPoint.push_back(Point(-Distance, -Distance, Distance));
    SkyBoxPoint.push_back(Point(-Distance, -Distance, -Distance));
    SkyBoxPoint.push_back(Point(Distance, -Distance, -Distance));
    SkyBoxPoint.push_back(Point(Distance, -Distance, Distance));
}
void SkyBox::ShowSky(){
    glEnable(GL_DEPTH_TEST);    
	glEnable(GL_TEXTURE_2D); 
    if(Surface[0] == 0){Surface[0] = loadTexture("texture/skybox/up.bmp");}
    if(Surface[1] == 0){Surface[1] = loadTexture("texture/skybox/down.bmp");}
    if(Surface[2] == 0){Surface[2] = loadTexture("texture/skybox/front.bmp");}
    if(Surface[3] == 0){Surface[3] = loadTexture("texture/skybox/left.bmp");}
    if(Surface[4] == 0){Surface[4] = loadTexture("texture/skybox/right.bmp");}
    if(Surface[5] == 0){Surface[5] = loadTexture("texture/skybox/back.bmp");}

    for(int i = 0; i < 6; i++){
        if(Surface[i] == 0){
            std::cerr << "图片加载失败" << std::endl;
            exit(0);
        }
    }

    for(int i=0; i<24; i+=4)
    {
        glBindTexture(GL_TEXTURE_2D, Surface[i/4]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(SkyBoxPoint[i].x, SkyBoxPoint[i].y, SkyBoxPoint[i].z);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(SkyBoxPoint[i+1].x, SkyBoxPoint[i+1].y, SkyBoxPoint[i+1].z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(SkyBoxPoint[i+2].x, SkyBoxPoint[i+2].y, SkyBoxPoint[i+2].z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(SkyBoxPoint[i+3].x, SkyBoxPoint[i+3].y, SkyBoxPoint[i+3].z);
        glEnd();
    }

    // glBindTexture(GL_TEXTURE_2D, Surface[3]);
    // glBegin(GL_QUADS);
    // glTexCoord2f(0.0f, 0.0f); glVertex3f(-Distance, -Distance, -Distance);
    // glTexCoord2f(0.0f, 1.0f); glVertex3f(-Distance, -Distance, Distance);
    // glTexCoord2f(1.0f, 1.0f); glVertex3f(Distance, -Distance, Distance);
    // glTexCoord2f(1.0f, 0.0f); glVertex3f(Distance, -Distance, -Distance);
    // glEnd();

    glDisable(GL_DEPTH_TEST);    
	glDisable(GL_TEXTURE_2D); 
}