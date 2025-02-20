#ifndef ebobEkok_H
#define ebobEkok_H

long int ebob(long int a,long int b) {//öklidin ebob bulma algoritması sayesinde 2 sayının ebobunu buluruz...

    //negatif sayıyı pozitif yapıp sonra ekoku alırız...
    if(a < 0)
        a = -a;
    if(b < 0)
        b = -b;

    while (b != 0) {
        long int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

long int ekok(long int a,long int b) {//matematikte ekok(a,b) * ebob(a,b) = 1 eşitliği sayesinde ebob yardımı ile ekoku kısa yoldan buluruz.
    
    //negatif sayıyı pozitif yapıp sonra ekoku alırız...
    if(a < 0)
        a = -a;
    if(b < 0)
        b = -b;

    return (a * b) / ebob(a, b);
}

#endif