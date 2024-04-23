#include <stdio.h>
#include<stdlib.h>
int main()

{

    system("play -n synth 0.1 sine 880 vol 0.5");
    system("play -n synth pl G2 pl B2 pl D3 pl G3 pl D4 pl G4     delay 0 .05 .1 .15 .2 .25 remix - fade 0 4 .1 norm -1");
    

}