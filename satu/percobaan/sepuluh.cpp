#include <stdio.h>
#include <math.h>

struct polar
{
    double r;
    double alpha;
};

struct kartesian
{
    double x;
    double y;
};



int main(int argc, char const *argv[])
{
    
    struct polar p1;
    struct kartesian k1;

    printf("Masukkan nilai r untuk koordinat polar : ");
    scanf("%lf", &p1.r);
    
    printf("Masukkan nilai alpha untuk koordinat polar : ");
    scanf("%lf", &p1.alpha);

    k1.x = p1.r * cos(p1.alpha);
    k1.y = p1.r * sin(p1.alpha);

    printf("Nilai koordinat kartesian untuk koordinat polar r = %2.21f alpha = %2.21f adalah : \n", p1.r, p1.alpha);
    printf("x = %2.21f\ty = %2.21f\n", k1.x, k1.y);

    return 0;
}
