# База по вычислительной геометрии

```
struct pt {
    int x{0}, y{0};
    pt() {}
    pt (int _x, int _y) { x = _x; y = _y; }
    pt (pt& p1, pt& p2) { auto pp = pt(p2.x - p1.x, p2.y - p1.y); x = pp.x; y = pp.y; }
    
    void load(){ cin>>this->x >> this->y; }
};

pt operator+(pt& a, pt& b) { return pt(a.x+b.x, a.y+b.y); }
pt operator-(pt& a, pt& b) { return pt(a.x-b.x, a.y-b.y); }
int operator*(pt& a, pt& b) { return a.x*b.x + a.y*b.y; }
int operator%(pt& a, pt& b) { return a.x*b.y - b.x*a.y; }
istream& operator>>(istream &in, pt &p) { 
    in >> p.x >> p.y;
    return in;
}
ostream& operator<<(ostream &out, pt &p) { 
    out << p.x << " " << p.y << endl;
    return out;            
}

ld len(pt a) { return sqrt(a.x*a.x + a.y*a.y); }

```