#include "transform.h"

void _Point3DToMatriex3D(VP& PointGroup, VMatrix3D& Matrix, bool PtoM){
    if(PtoM)
        for(auto i : PointGroup){
            Matrix3D t = {i.x, i.y, i.z, 1.0};
            Matrix.push_back(t);
        }
    else{
        int j = 0;
        for(auto i : Matrix){
            Point t = {i.x, i.y, i.z};
            PointGroup[j] = t;
            ++j;
        }
    }
}

void _Point2DToMatriex2D(VP2& PointGroup, VMatrix2D& Matrix, bool PtoM){
    if(PtoM)
        for(auto i : PointGroup){
            Matrix2D t = {i.x, i.y, 1.0};
            Matrix.push_back(t);
        }
    else{
        int j = 0;
        for(auto i : Matrix){
            Point2d t = {i.x, i.y};
            PointGroup[j] = t;
            ++j;
        }
    }
}

void _MultipleMatriex3D(VMatrix3D& MatrixA_IN, VMatrix3D& MatrixB_IN){
    UINT j2 = 0;
    for(auto& i : MatrixA_IN){
        double tl[4] = {0.0, 0.0, 0.0, 0.0};
        for(auto j : MatrixB_IN){
            double t = 0;
            t += i.x * j.x;
            t += i.y * j.y;
            t += i.z * j.z;
            t += i.N * j.N;
            tl[j2] = t;
            j2 = (j2+1)%4;
        }
        i = Matrix3D(tl[0],tl[1],tl[2],tl[3]);
    }
}

void _MultipleMatriex2D(VMatrix2D& MatrixA_IN, VMatrix2D& MatrixB_IN){
    UINT j2 = 0;
    for(auto& i : MatrixA_IN){
        double t = 0;
        double tl[3] = {0.0, 0.0, 0.0};
        for(auto j : MatrixB_IN){
            t += i.x * j.x;
            t += i.y * j.y;
            t += i.N * j.N;
            tl[j2] = t;
            j2 = (j2+1)%3;
        }
        i = Matrix2D(tl[0],tl[1],tl[2]);
    }
}


void PrintPoint(const VP& Point){
	for(auto i : Point){
        std::cout << i.x << " " << i.y << " " << i.z << std::endl;
    }
}

void PrintMatriex3D(const VMatrix3D& Matrix){
    for(auto i : Matrix){
        std::cout << i.x << " " << i.y << " " << i.z << " " << i.N << std::endl;
    }
}

//平移矩阵
void _translate(VMatrix3D &In, double l, double m, double n){
    VMatrix3D TM;
    TM.push_back(Matrix3D(1.0, 0.0, 0.0, l));
    TM.push_back(Matrix3D(0.0, 1.0, 0.0, m));
    TM.push_back(Matrix3D(0.0, 0.0, 1.0, n));
    TM.push_back(Matrix3D(0.0, 0.0, 0.0, 1.0));
    _MultipleMatriex3D(In, TM);
}

void translate(VP &v, double l, double m, double n){
    VMatrix3D tm;
    _Point3DToMatriex3D(v,tm,true);
    _translate(tm,l,m,n);
    _Point3DToMatriex3D(v,tm,false);
}

void translateX(VP &v, double l){translate(v,l,0.0,0.0);}
void translateY(VP &v, double m){translate(v,0.0,m,0.0);}
void translateZ(VP &v, double n){translate(v,0.0,0.0,n);}

//旋转矩阵
void _rotate(VMatrix3D &In, double x, double y, double z){
    VMatrix3D TM;
    TM.push_back(Matrix3D(cos(z)*cos(y), -sin(z)*cos(y), sin(y), 0));
    TM.push_back(Matrix3D(sin(z)*cos(x)+cos(z)*sin(y)*sin(x), cos(z)*cos(x)-sin(z)*sin(y)*sin(x), -cos(y)*sin(x), 0));
    TM.push_back(Matrix3D(sin(z)*sin(x)-cos(z)*sin(y)*cos(x), cos(z)*sin(x)+sin(z)*sin(y)*cos(x), cos(y)*cos(x), 0));
    TM.push_back(Matrix3D(0.0, 0.0, 0.0, 1.0));
    _MultipleMatriex3D(In, TM);
}

void rotateDXYZ(VP &v, double angle1, double angle2, double angle3){
    VMatrix3D tm;
    _Point3DToMatriex3D(v,tm,true);
    _rotate(tm,2*PI-angle1*PI/180,2*PI-angle2*PI/180,2*PI-angle3*PI/180);
    _Point3DToMatriex3D(v,tm,false);
}

void rotateDX(VP &v, double angle){rotateDXYZ(v,angle, 0.0, 0.0);}
void rotateDY(VP &v, double angle){rotateDXYZ(v,0.0, angle, 0.0);}
void rotateDZ(VP &v, double angle){rotateDXYZ(v,0.0, 0.0, angle);}

//缩放
void _scaleXYZ(VMatrix3D &In, double a, double e, double i){
	VMatrix3D TM;
    TM.push_back(Matrix3D(a, 0.0, 0.0, 0.0));
    TM.push_back(Matrix3D(0.0, e, 0.0, 0.0));
    TM.push_back(Matrix3D(0.0, 0.0, i, 0.0));
    TM.push_back(Matrix3D(0.0, 0.0, 0.0, 1));
    _MultipleMatriex3D(In, TM);
}

void scaleXYZ(VP &v, double a, double e, double i){
    VMatrix3D tm;
    _Point3DToMatriex3D(v,tm,true);
    _scaleXYZ(tm,a,e,i);
    _Point3DToMatriex3D(v,tm,false);
}

void scaleX(VP &v, double a){scaleXYZ(v,a,1.0,1.0);}
void scaleY(VP &v, double e){scaleXYZ(v,1.0,e,1.0);}
void scaleZ(VP &v, double i){scaleXYZ(v,1.0,1.0,i);}
void scaleEntirety(VP &v, double s){scaleXYZ(v,s,s,s);};

//俯视图
// void _TTop(VMatrix3D &In){
//     VMatrix3D TM;
//     TM.push_back(Matrix3D(1.0, 0.0, 0.0, 0.0));
//     TM.push_back(Matrix3D(0.0, 1.0, 0.0, 0.0));
//     TM.push_back(Matrix3D(0.0, 0.0, 0.0, 0.0));
//     TM.push_back(Matrix3D(0.0, 0.0, 0.0, 1.0));
//     _MultipleMatriex3D(In, TM);
// }

VP2 TTop(const VP &v){
    // VMatrix3D tm;
    // _Point3DToMatriex3D(v,tm,true);
    // _TTop(tm);

    VP2 vp;
    for(auto i : v){
        vp.push_back(Point2d(i.x, i.y));
    }
    return vp;
}