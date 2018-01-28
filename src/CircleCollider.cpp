#include "../include/CircleCollider.h"

CircleCollider::CircleCollider(float x, float y, float radius): _x(x),_y(y),_radius(radius)
{
    //ctor
}

CircleCollider::~CircleCollider()
{
    //dtor
}

bool CircleCollider::Collision(float x, float y)
{
    return !(MathLib::SquareDistance(x,y,_x,_y)>_radius*_radius);
}

bool CircleCollider::Collision(Point& p)
{
    return Collision(p.x,p.y);
}

bool CircleCollider::Collision(PointCollider& c)
{
    return Collision(c.GetPoint().x,c.GetPoint().y);
}

bool CircleCollider::Collision(CircleCollider& c)
{
    return !(MathLib::SquareDistance(c._x, c._y, _x, _y) > (_radius+c._radius)*(_radius+c._radius));
}

bool CircleCollider::Collision(Point& a, Point& b)
{
    Vector u(a,b);       ///Vecteur directionnel de la droite

    Vector AC(a,Point(_x,_y));          ///Vecteur directionnel de la droite centre-point de contact

    float numerator = Vector::Determinant(u,AC);  ///Norme du vecteur v
    if(numerator < 0)
        numerator = -numerator; ///Valeur absolue du numérateur

    float denominator = u.Norm();    ///Norme de U
    float CI = numerator/denominator;
    return (CI<_radius);
}

bool CircleCollider::Collision(SegmentCollider& s)
{
    Point  a=s.GetA(),
            b=s.GetB();

    if(!Collision(a,b)) ///On test si la droite portant le segment touche le cercle
        return false;

    Vector AB(a,b),AC(a,Point(_x,_y)),BC(b,Point(_x,_y));
    /*AB.x = b.X()-a.X(); ///Vecteur du segment
    AB.y = b.Y()-a.Y();
    AC.x = _x-a.X();  ///Vecteurs entre le segment et le centre du cercle
    AC.x = _y-a.Y();
    BC.x = _x-b.X();
    BC.x = _y-b.Y();*/

    float pscal1 = Vector::ScalarProduct(AB,AC);   ///Produit scalaire
    float pscal2 = Vector::ScalarProduct(-AB,BC);

    if(pscal1>=0 && pscal2>=0)  ///Le segment travers le cercle de par en par
        return true;

    return (Collision(a) || Collision(b));   ///Sinon on test si l'une des extrémités du segment est dans le cercle
}

bool CircleCollider::Collision(AABBCollider& box)
{
    AABBCollider* surroudingBox=GetSurroundingAABB();

    if(!surroudingBox)
        return false;
    if(!surroudingBox->Collision(box))           ///Si les AABB entourant le cercle sont en collision
        return false;

    Point tl=box.GetPointTopLeft(),
            bl=box.GetPointBottomLeft(),
            tr=box.GetPointTopRight(),
            br=box.GetPointBottomRight();
    if(Collision(tl)         ///Si les points de la box sont dans le cercle
       || Collision(bl)
       || Collision(tr)
       || Collision(br))
        return true;

    if(box.Collision(GetCenter().x,GetCenter().y))  ///Si le centre du cercle est dans la box
        return true;

    ///Si la box traverse le cercle
    return MathLib::ProjectionOnSegment(GetCenter(), box.GetPointTopLeft(), box.GetPointBottomLeft())       ///Projection verticale
            || MathLib::ProjectionOnSegment(GetCenter(), box.GetPointTopLeft(), box.GetPointTopRight());    ///Projection horizontale
}

AABBCollider* CircleCollider::GetSurroundingAABB()
{
    AABBCollider* c = new AABBCollider(_x-_radius,_y-_radius,_radius+_radius,_radius+_radius);
    return c;
}

Point CircleCollider::GetCenter()
{
    Point a;
    a.x=_x;
    a.y=_y;
    return a;
}

void CircleCollider::SetPosition(float x, float y)
{
    _x=x;
    _y=y;
}
