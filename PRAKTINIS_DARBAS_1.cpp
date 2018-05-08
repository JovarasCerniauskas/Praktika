#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
using namespace std;
void fight();
void loot_drop();
struct brolis
{
    int hp;
    int power;
    int vallet;
    string head;
    string chest;
    string legs;
    string weapon;
    int deff_head;
    int deff_chest;
    int deff_legs;
} brother[1];
string room[4]={" Karaliaus kapas...\n Cia ilsisi Milzinu karalius...\n Jeigu ilgai ir tyliai klausysi, gali isgirsti, alsavima is karaliaus kapo...\n Buk pagarbus ir netrukdyk senojo karaliaus amzinojo poilsio... ",
" Sena koplycia...\n Senojo pasaulio zmones, cia garbino dievus...\n Prisieke meile vienas kitam...\n Apraudojo mirusiuosius....\n Pasitiko gimusius...\n Po tiek amziu, vis dar galima jausti tikejimo aura... ",
" Marmurinis takelis salia Veneros liepos...\n Isimylejeliu pamekta vietele...\n Veneros liepos sakos nusetos kristoliniais ziedais, kurios pakabino isimylejeliai\n Svieciant menuliui pro pozemiu plysius, liepa ir visi ziedai nusvinta...\n apsviestami visa uola ir joje esancius... Magiska \n Tokioje vietoje niekada nesijausi vienas... NIEKADA... ",
" Suolelis salia medaus ezerelio...\n Vienisas suolelis apzvelgentis medaus ezereli...Siltais Birzelio vakarais, ezerelis prakvimpa medum...\n Taip jis ir gavo savo varda...\n Atsirado praeiviu, bandziusiu atsigerti kvepencio ezerelio vandens...\n Gerti nepatartina... " };
struct priesas
{
    int place;
    string name;
    int lp;
    int str;
    int def;
}enemy[1];
void enemy_creation(int one,string nam, int lip, int sthr, int deef)
{
    enemy->place=one;
    enemy->name=nam;
    enemy->lp=lip;
    enemy->str=sthr;
    enemy->def=deef;
}
void gen_room()
{

int gen=rand() %4;
for(int i=0;i<5;i++){
    if(i==gen){
        cout << room[i] << endl;
        break;
    }
}

}
void istorija()
{
    cout << " Du broliai nusprende patyrineti netoli namu esancias uolas..." << endl;
    cout << " Jie nukrenta i pozemini labirinta - " << endl;
    cout << " Milzinu kapai " << endl;
    cout << " Tikslas - isgyventi ir gryzti namo pas tevus " << endl;
    cout << " Broliai : " << endl;
    cout << " 1. Spirgis " << endl;
    cout << " 2. Virgis  " << endl;
    cout << " Kuri renkiesi? " << endl;
}
string shop_stuff[]= {"plieninis salmas", "plieniniai sarvai ",  "plieniniai koju sarvai","meteorito kujis", "kalavijas"};
int shop_price[]= {50,50,50,50,50};
string head_stuff[]= {"kepure", "medinis salmas", "odinis salmas", " metalinis salmas ", "plieninis salmas"};
int head_points[]= {5,10,20,25,30};
string chest_stuff[]= {"marskiniai", "mediniai sarvai", " odiniai sarvai", "metaliniai sarvai", "plieniniai sarvai "};
int chest_points[]= {5,10,20,25,30};
string legs_stuff[]= {"kelnes"," mediniai koju sarvai", "odiniai koju sarvai", "metaliniai koju sarvai", "plieniniai koju sarvai"};
int legs_points[]= {5,10,20,25,30};
string melee_stuff[]= {"lazda","kuoka", "metalinis vamzdis", "sventojo azuolo saknis", "meteorito kujis"};
int melee_points[]= {10,30,50,70,80};
string range_stuff[]= {"peilis","mrumpas kardas", "zalvario kardas", "metalinis kirvis","kalavijas"};
int range_points[]={15,20,35,50,55};
void spirgis()
{
    brother->hp=1500;
    brother->vallet=10000;
    brother->head=head_stuff[0];
    brother->chest=chest_stuff[0];
    brother->legs=legs_stuff[0];
    brother->weapon=melee_stuff[0];
    brother->power=melee_points[0];
    brother->deff_head=head_points[0];
    brother->deff_chest=chest_points[0];
    brother->deff_legs=legs_points[0];
}
bool check=false;
void virgis()
{
    brother->hp=1000;
    brother->vallet=10000;
    brother->head=head_stuff[0];
    brother->chest=chest_stuff[0];
    brother->legs=legs_stuff[0];
    brother->weapon=range_stuff[0];
    brother->power=range_points[0];
    brother->deff_head=head_points[0];
    brother->deff_chest=chest_points[0];
    brother->deff_legs=legs_points[0];
}
void pauze()
{
    system("pause");
    system("cls");
}
void virgis_info()
{
    cout << " Virgis yra jaunesnysis brolis. " << endl;
    cout << " Vidutinis gyvybes tasku kiekis " << endl;
    cout << " Daro mazai atakos, bet gali issauti kelias streles/akmenis vienu puolimu " << endl;
    cout << " Gerai valdo " << endl;
}
void spirgis_info()
{
    cout << " Spirgis yra vyresnysis brolis. " << endl;
    cout << " Turi daug gyvybes tasku" << endl;
    cout << " Daro dideli kieki atakos vienu ejimu " << endl;
    cout << " negali naudoti lanku ir laidyniu " << endl;
}
void stars()
{
    for(int i=0; i<10; i++)
    {
        cout << "--";
    }
    cout << endl;
}
string item;
int daiktas;
int shop;
string kazkas;
string inventory_name[5]={""};
void inventory_swap()
{
    for(int i=0; i<5; i++)
    {
        if(head_stuff[i]==item)
        {

            swap(brother->head,inventory_name[daiktas-1]);
            brother->deff_head = head_points[i];
            cout << brother->deff_head << endl;
            break;

        }
    }
    for(int i=0; i<5; i++)
    {
        if(chest_stuff[i]==item)
        {
            swap(brother->chest,inventory_name[daiktas-1]);

            brother->deff_chest=chest_points[i];
            cout << brother->deff_chest << endl;
            break;
        }
    }
    for(int i=0; i<5; i++)
    {
        if(legs_stuff[i]==item)
        {
            swap(brother->legs,inventory_name[daiktas-1]);
            brother->deff_legs= legs_points[i];
            cout << brother->deff_legs << endl;
            break;
        }
    }
    for(int i=0; i<5; i++)
    {
        if(melee_stuff[i]==item)
        {
            swap(brother->weapon,inventory_name[daiktas-1]);
            brother->power=melee_points[i];
            break;
        }
    }
    for(int i=0; i<5; i++)
    {
        if(range_stuff[i]==item)
        {
            swap(brother->weapon,inventory_name[daiktas-1]);
            brother->power=range_points[i];
            break;
        }
    }

}
string shop_item;
void emty_space()
{
    int vieta;
    bool yra=true;
for(int i=0;i<5;i++){

    vieta=i;
    break;
}
    inventory_name[vieta]=shop_item;
    if(!yra){
        cout << "vietos nera " << endl;
    }

}
bool laisva=false;
void krautuve()
{
    int pinigai=brother->vallet;
    if(pinigai>=shop_price[shop-1])
    {
        for(int i=0; i<5; i++)
        {
            if(shop_item==shop_stuff[i])
                for(int j=0; j<5; j++)
                {
                	if(inventory_name[j]=="")
                	{
                		int vieta=j;
                		laisva=true;

                		inventory_name[i]=shop_stuff[i];
                		break;
                }
					}
					   if(laisva==false)
                {
                	cout<<"Laisvos vietos nėra"<<endl;
                }
                inventory_name[shop-1]=shop_stuff[shop-1];
                break;
        }
        brother->vallet=pinigai-shop_price[shop-1];
    }

    else
        cout << " Neturite pakankamai pinigu nusipirkti... " << endl;
}

void sell_stuff()
{
    int pinigai=brother->vallet;
    for(int i=0;i<5;i++){
        if(item==inventory_name[shop-1])
        {
            inventory_name[shop-1]="";
            brother->vallet=pinigai+shop_price[shop-1];
        }
    }
}
void inventory_emty()
{
    bool check=false;
    for(int i=0;i<5;i++)
{
    if(inventory_name[i]!="")
        check=true;
}
if(check==false){
    cout << " Jus nieko neturi krepsyje... " << endl;
}

else {
        int b=1;
    for(int i=0; i<5; i++)
            {

                cout <<  b <<inventory_name[i] << endl;
                b++;
            }
}
}
int health_1=150;
int health_2=100;
int main()
{
    srand(time(NULL));
    stars();
    int taip;
    int pasirinkimas;
    istorija();
    cin >> pasirinkimas;
    stars();
    while(pasirinkimas!=taip)
    {
        if(pasirinkimas==1)
        {
            cout << " pasirinktas Spirgis " << endl;
            spirgis();
            spirgis_info();
            break;
            stars();
        }
        else if(pasirinkimas==2)
        {
            cout << " pasirinktas Virgis " << endl;
            virgis();
            virgis_info();
            break;
            stars();
        }
        else
            cout << " blogai pasirinktas veikejas " << endl;
        cin >> pasirinkimas;
    }
    int option=420;
    stars();
    while(option!=0)
    {
        cout << "1. Perziureti veikejo daiktus " << endl;
        cout << "2. Perziureti veikejo bukle " << endl;
        cout << "3. Uzisideti  daiktus " << endl;
        cout << "4. Parduotuve" << endl;
        cout << "5. Keliauti tolyn" << endl;
        cin >> option;
        stars();
        if(option==1)
        {
            cout << "Veikejo uzsideti daiktai: " << endl;
            cout << "+ " << "Pinigai"  << " - " << brother->vallet << "$ " << endl;
            cout << "+ " << "Galva "   << " - " << brother->head << endl;
            cout << "+ " << "Krutine " << " - " << brother->chest << endl;
            cout << "+ " << "Kojos "   << " - " << brother->legs << endl;
            cout << "+ " << "Ginklas " << " - " << brother->weapon << endl;
            cout << "Veikejo daiktai krepsi : " << endl;
            inventory_emty();
            stars();
        }
        if(option==2)
        {
            cout << " veikejo bukle: " << endl;
            stars();
            cout << " Veikejo gyvybes taskai - + " << brother->hp << endl;
            cout << " Veikejo daromi atakos taskai - { " << brother->power << " } " <<  endl;
            cout << " Veikejo apsaugos taskai - [ " << brother->deff_head + brother->deff_chest + brother->deff_legs << " ] " << endl;
            stars();
        }
        if(option==3)
        {
            bool changer=false;
    for(int i=0;i<5;i++)
{
    if(inventory_name[i]!="")
        changer=true;
}
if(changer==false){
    cout << " Jus nieko neturi krepsyje... " << endl;
    stars();
}
else {
        cout << " Kuri daikta norite uzsideti ? : " << endl;
            int a=1;
            for(int i=0; i<5; i++)
            {
                cout << a <<  ". - " << inventory_name[i] << endl;
                a++;
            }
            cin >> daiktas;
            for(int i=0; i<5; i++)
            {
                if(i == daiktas-1)
                {
                    item=inventory_name[i];
                    break;
                }
            }
            inventory_swap();
}
        }
        if(option==4)
        {
            int s=1;
            int man;
            while(man!=69)
            {
                cout << "Ka veikiate krautuveje ? : " << endl;
                cout << "1. Pirku daiktus " << endl;
                cout << "2. Parduodu daiktus " << endl;
                cout << "3. Gristu atgal " << endl;
                cin >> man;
                if(man==1)
                {
                    int s=1;
                    cout << "Kuri daikta norite pirkti ? : " << endl;
                    for(int i=0; i<5; i++)
                    {
                        cout << s << shop_stuff[i] << " || " <<  "Kaina -  " << shop_price[i] << "$" <<endl;
                        s++;
                    }
                    cin >> shop;
                    for(int i=0; i<5; i++)
                    {
                        if(i == shop-1)
                        {
                            shop_item=shop_stuff[i];
                            break;
                        }
                    }
                    krautuve();
                }
                int u=1;
                if(man==2)
                {
                    s=1;
                    cout << " Kuri daikta norite parduoti? " << endl;
                    for(int i=0; i<5; i++)
                    {
                        cout << u << inventory_name[i] << endl;
                        u++;
                    }
                   cin >> shop;
                   for(int i=0; i<5; i++)
                    {
                        if(i == shop-1)
                        {
                            item=inventory_name[i];
                            break;
                        }
                    }
                    sell_stuff();
                }
                if(man==3)
                {
                    break;
                }
            }
        }
        if(option==5)
        {
            gen_room();
            cout << " Tu kovosi su " << endl;
            int gene=rand() %8;
    if(gene==0){
            enemy_creation(0,"Minotauru",88,25,4);
cout << enemy->name << endl;
    }
    if(gene==1){
            enemy_creation(1,"Vaiduokliu", 15, 23, 0);
cout << enemy->name << endl;
    }
if(gene==2){
        enemy_creation(2,"Ziurke", 20, 16, 5);
cout << enemy->name << endl;
    }
if(gene==3){
    enemy_creation(3,"Zaliuoju velniu", 50, 21, 7);
cout << enemy->name << endl;
    }
if(gene==4){
    enemy_creation(4,"Pelkiu skenduoliu", 30, 16, 9);
cout << enemy->name << endl;
    }
    enemy_creation(5,"Lygumu golemu", 87, 20, 4);
    if(gene==5){
        enemy_creation(5,"Lygumu golemu", 87, 5, 5);
cout << enemy->name << endl;
    }
      if(gene==6){
          enemy_creation(6,"Smelynu zalciu", 40, 15, 2);
cout << enemy->name << endl;
    }
    if(gene==7){
        enemy_creation(7,"Pozemiu valdovu, Panteonu", 200, 69, 6);
cout << enemy->name << endl;
    }
fight();
loot_drop();
    }
        }
    }
    string loot[5]={" ","Bambos pukai", "Majonezo skonio jogurtas", "Vazelino trapuciai","Skolos lapelis"};
    int loot_price[5]={0,10,70,80,90};
    int loot_rarity[5]={0,1000,1500,2000,3000};
    void loot_drop()
    {
        for(int i=0;i<5;i++){
                if(inventory_name[i]==""){

        int drop=rand() %3000;
        if(drop>loot_rarity[0]&&drop<=loot_rarity[1])
        {
            inventory_name[i]=loot[0];
            cout << " Jus gavote : " << " Nieko " << endl;
            break;
        }
        if(drop>loot_rarity[1]&&drop<=loot_rarity[2])
        {
            inventory_name[i]=loot[1];
            cout << " Jus gavote : " << inventory_name[i] << endl;
            break;
        }
        if(drop>loot_rarity[2]&&drop<=loot_rarity[3])
        {
            inventory_name[i]=loot[2];
            cout << " Jus gavote : " << inventory_name[i] << endl;
            break;
        }
        if(drop>loot_rarity[3]&&drop<=loot_rarity[4])
        {
            inventory_name[i]=loot[3];
            cout << " Jus gavote : " << inventory_name[i] << endl;
            break;
        }
        if(drop>loot_rarity[4]&&drop<=loot_rarity[5])
        {
            inventory_name[i]=loot[4];
            cout << " Jus gavote : " << inventory_name[i] << endl;
            break;
        }
        }
        }


    }
    void fight()
{
    int battle;
    int life;
    int bad_life;
    int shield=brother->deff_chest+brother->deff_head+brother->deff_legs;
    int player_dmg=brother->power-(enemy->def/2);
    int enemy_dmg=enemy->str-(shield/10);
     life=brother->hp-enemy_dmg;
        bad_life=enemy->lp-player_dmg;
while(battle!=0)
    {
        life=life-enemy_dmg;
        bad_life=bad_life-player_dmg;
        cout << "jusu gyvybe: "<<life << endl;
        cout << "Prieso gyvybe: " << bad_life << endl;
        pauze();
        if(life<=0)
        {
            cout << " Jus mirete, zaidimo pabaiga.. " <<endl;
            exit(0);
        }
        else if(bad_life<=0)
        {
            cout << " jus laimejote! " << endl;
            battle=0;
        }

    }

}


