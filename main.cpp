#include <fstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;
ifstream f ("jucatori.txt");
struct jucator
{
    char nume[50];
    char prenume[50];
    char tara [50];
    char liga[50];
    char club[50];
    char pozitie[50];
    int nr;
    int varsta;
}tmp,tgt,gss;

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m"; 
const string RESET = "\033[0m";
const string BLUE = "\033[34m";         
const string PURPLE = "\033[35m";       
const string CYAN = "\033[36m";         
const string ORANGE = "\033[38;5;208m";

int x,k,ok=1,corect,gasit,again=1;
char incercarenume[50],incercareprenume[50],raspuns;
int main()
{
    while(again)
    {
        corect=0;
        srand(time(0));
        while (f>>tmp.nume>>tmp.prenume>>tmp.tara>>tmp.liga>>tmp.club>>tmp.pozitie>>tmp.nr>>tmp.varsta)
            k++;
        f.close();
        f.clear();
        x=rand()%k;
        f.open("jucatori.txt");
        k=0;
        while(f>>tgt.nume>>tgt.prenume>>tgt.tara>>tgt.liga>>tgt.club>>tgt.pozitie>>tgt.nr>>tgt.varsta)
        {
            if (k==x)
                break;
            k++;
        }
        f.close();
        while (corect==0)
        {
            cout<<CYAN<<"Guess!"<<RESET<<'\n';
            cin>>incercarenume>>incercareprenume;
            if (strcmp(incercarenume,"give")==0 && strcmp(incercareprenume,"up")==0)
            {
                cout<<PURPLE<<"Jucatorul era "<<tgt.nume<<" "<<tgt.prenume<<RESET;
                return 0;
            }
            f.open("jucatori.txt");
            gasit=0;
            while (f>>tmp.nume>>tmp.prenume>>tmp.tara>>tmp.liga>>tmp.club>>tmp.pozitie>>tmp.nr>>tmp.varsta)
            {
                if(strcmp(incercarenume,tmp.nume)==0 && strcmp(incercareprenume,tmp.prenume)==0)
                {
                    strcpy(gss.nume,tmp.nume);
                    strcpy(gss.prenume,tmp.prenume);
                    strcpy(gss.tara, tmp.tara);
                    strcpy(gss.liga, tmp.liga);
                    strcpy(gss.club, tmp.club);
                    strcpy(gss.pozitie, tmp.pozitie);
                    gss.nr=tmp.nr;
                    gss.varsta=tmp.varsta;
                    gasit=1;
                    break;
                }
            }
            f.close();
            if (gasit==0)
                cout<<ORANGE<<"Jucatorul nu este in lista"<<RESET<<'\n';
            else 
            {
                if (strcmp(gss.tara,tgt.tara)==0)
                    cout<<GREEN<<gss.tara<<RESET<<" ";
                else cout<<RED<<gss.tara<<RESET<<" ";
    
                if (strcmp(gss.liga,tgt.liga)==0)
                    cout<<GREEN<<gss.liga<<RESET<<" ";
                else cout<<RED<<gss.liga<<RESET<<" ";
    
                if (strcmp(gss.club,tgt.club)==0)
                    cout<<GREEN<<gss.club<<RESET<<" ";
                else cout<<RED<<gss.club<<RESET<<" ";
    
                if (strcmp(gss.pozitie, tgt.pozitie)==0)
                    cout<<GREEN<<gss.pozitie<<RESET<<" ";
                else cout<<RED<<gss.pozitie<<RESET<<" ";
    
                if (gss.nr==tgt.nr)
                    cout<<GREEN<<gss.nr<<RESET<<" ";
                else if (gss.nr<tgt.nr)
                    cout<<RED<<"bigger"<<RESET<<'('<<gss.nr<<") ";
                else cout<<RED<<"smaller"<<RESET<<'('<<gss.nr<<") ";
    
                if (gss.varsta==tgt.varsta)
                    cout<<GREEN<<gss.varsta<<RESET<<" ";
                else if (gss.varsta<tgt.varsta)
                    cout<<RED<<"older"<<RESET<<'('<<gss.varsta<<") ";
                else cout<<RED<<"younger"<<RESET<<'('<<gss.varsta<<") ";
    
                if (strcmp(gss.nume,tgt.nume)==0 && strcmp(gss.prenume,tgt.prenume)==0)
                {
                    corect = 1;
                    cout<<PURPLE<<"Felicitari!"<<RESET<<'\n';
                }
                if (corect==1)
                {
                    cout<<BLUE<<"Try again? (Y/N)"<<RESET;
                    cin>>raspuns;
                    if(raspuns=='N')
                        again=0;
                    else while (raspuns!='Y' && raspuns!='N')
                    {
                        cout<<BLUE<<"Y or N "<<RESET;
                        cin>>raspuns;
                        if (raspuns=='N')
                            again=0;
                    }
                }
            }
        }
    }
    return 0;
}