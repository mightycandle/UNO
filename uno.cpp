#include<bits/stdc++.h>
#define ll long long
#define ivec vector<int>
#define llvec vector<long long>
#define svec vector<string>
#define pb push_back
#define F(i,a,b) for(int i=a;i<b;i++)
using namespace std;
svec vals={"0","1","2","3","4","5","6","7","8","9","Skip","Rev","+2","Wild","+4"};
svec getdeck(){
    svec deck;
    string s;
    F(i,0,15){
        s=vals[i];
        if(s!="Wild" && s!="+4" && s!="0"){
            deck.pb("1"+s);
            deck.pb("2"+s);
            deck.pb("3"+s);
            deck.pb("4"+s);
            deck.pb("1"+s);
            deck.pb("2"+s);
            deck.pb("3"+s);
            deck.pb("4"+s);
        }
        else if(s=="Wild" || s=="+4"){
            deck.pb("5"+s);
            deck.pb("5"+s);
            deck.pb("5"+s);
            deck.pb("5"+s);
        }
        else if (s=="0"){
            deck.pb("1"+s);
            deck.pb("2"+s);
            deck.pb("3"+s);
            deck.pb("4"+s);
        }
    }
    return deck;
}
void printcard(string s,svec deck){
    //string s=deck[x];
    cout<<"\033[1;3"<<s[0]<<"m"<<s.substr(1,s.size()-1)<<"\033[0m";
    cout<<" ";
}
void showhid(string top,svec deck,ivec pdeck,ivec cdeck){
    cout<<"Computer's deck:"<<endl;
    F(i,0,cdeck.size()){
        if(i<10)
            cout<<string(3,'-')<<i<<string(4,'-')<<"  ";
        else
            cout<<string(3,'-')<<i<<string(3,'-')<<"  ";
    }
    cout<<endl;
    F(i,0,cdeck.size())
        cout<<"|      |  ";
    cout<<endl;
    F(i,0,cdeck.size())
        cout<<"|  ?   |  ";
    cout<<endl;
    F(i,0,cdeck.size())
        cout<<"|      |  ";
    cout<<endl;
    F(i,0,cdeck.size())
        cout<<string(8,'-')<<"  ";
    cout<<endl;
}
void showcomp(string top,svec deck,ivec pdeck,ivec cdeck){
    cout<<"Computer's deck:"<<endl;
    F(i,0,cdeck.size()){
        if(i<10)
            cout<<string(3,'-')<<i<<string(4,'-')<<"  ";
        else
            cout<<string(3,'-')<<i<<string(3,'-')<<"  ";
    }
    cout<<endl;
    F(i,0,cdeck.size())
        cout<<"|      |  ";
    cout<<endl;
    F(i,0,cdeck.size())
        cout<<"|      |  ";
    cout<<endl;
    F(i,0,cdeck.size()){
        string x=deck[cdeck[i]];
        int y=x.size()-1;
        if(y==1 || y==2)
            cout<<"|  ";
        else
            cout<<"|"<<string(2-y%3,' ');
        printcard(x,deck);
        if(y==1 || y==2)
            cout<<string(3-y,' ')<<"|  ";
        else
            cout<<string(3-y+y%3,' ')<<"|  ";
    }
    cout<<endl;
    F(i,0,cdeck.size())
        cout<<"|      |  ";
    cout<<endl;
    F(i,0,cdeck.size())
        cout<<"|      |  ";
    cout<<endl;
    F(i,0,cdeck.size())
        cout<<string(8,'-')<<"  ";
    cout<<endl;

}
void showmine(string top,svec deck,ivec pdeck,ivec cdeck){
    cout<<"Your deck: "<<endl;
    F(i,0,pdeck.size()){
        if(i<10)
            cout<<string(3,'-')<<i<<string(4,'-')<<" ";
        else
            cout<<string(3,'-')<<i<<string(3,'-')<<" ";
    }
    cout<<endl;
    F(i,0,pdeck.size())
        cout<<"|      | ";
    cout<<endl;
    F(i,0,pdeck.size())
        cout<<"|      | ";
    cout<<endl;
    F(i,0,pdeck.size()){
        string x=deck[pdeck[i]];
        int y=x.size()-1;
        if(y==1 || y==2)
            cout<<"|  ";
        else
            cout<<"|"<<string(2-y%3,' ');
        printcard(x,deck);
        if(y==1 || y==2)
            cout<<string(3-y,' ')<<"| ";
        else
            cout<<string(3-y+y%3,' ')<<"| ";
    }
    cout<<endl;
    F(i,0,pdeck.size())
        cout<<"|      | ";
    cout<<endl;
    F(i,0,pdeck.size())
        cout<<"|      | ";
    cout<<endl;
    F(i,0,pdeck.size())
        cout<<string(8,'-')<<" ";
    cout<<endl;
}
void testcase(){
    string top="35";
    cout<<endl<<"Example:"<<endl;
    cout<<string(6,' ')<<string(3,'-')<<"4"<<string(4,'-')<<endl;
    cout<<string(6,' ')<<"|"<<string(6,' ')<<"|"<<endl;
    cout<<string(6,' ')<<"|"<<string(6,' ')<<"|"<<endl;
    int y=top.size()-1;
    cout<<string(6,' ')<<"|  ";
    cout<<"\033[1;3"<<top[0]<<"m"<<top.substr(1,top.size()-1)<<"\033[0m";
    cout<<string(4-y,' ')<<"|   "<<endl;
    cout<<string(6,' ')<<"|"<<string(6,' ')<<"|"<<endl;
    cout<<string(6,' ')<<"|"<<string(6,' ')<<"|"<<endl;
    cout<<string(6,' ')<<string(8,'-')<<endl;
}
void showtop(string top,svec deck){
    cout<<endl<<"Top card of pile"<<endl;
    cout<<string(8,'-')<<endl;
    cout<<"|"<<string(6,' ')<<"|"<<endl;
    cout<<"|"<<string(6,' ')<<"|"<<endl;
    int y=top.size()-1;
    if(y==1 || y==2)
        cout<<"|  ";
    else
        cout<<"|"<<string(2-y%3,' ');
    printcard(top,deck);
    if(y==1 || y==2)
        cout<<string(3-y,' ')<<"|   "<<endl;
    else
        cout<<string(3-y+y%3,' ')<<"|   "<<endl;
    cout<<"|"<<string(6,' ')<<"|"<<endl;
    cout<<"|"<<string(6,' ')<<"|"<<endl;
    cout<<string(8,'-')<<endl<<endl;
}
void printall(string top,svec deck,ivec pdeck,ivec cdeck){
    showhid(top,deck,pdeck,cdeck);
    //showcomp(top,deck,pdeck,cdeck);
    showtop(top,deck);
    showmine(top,deck,pdeck,cdeck);
}

string init(ivec stock,svec deck){
    int i=0;
    string ss;
    int loop=0;
    while (i<108){
        string s=deck[stock[i]];
        string s1=deck[stock[i]].substr(1,deck[stock[i]].size()-1);
        if(s1!="Skip" && s1!="Rev" && s1!="+2" && s1!="Wild" && s1!="+4"){
            int x=stock[i]+1;
            stock.erase(stock.begin()+i);
            x-=1;
            //printcard(s,deck);
            ss=s;
            return s;
            break;
        }
        else{
            i+=1;
        }
    }
    return ss;
}
ivec splitdeck(svec deck,ivec pdeck,ivec cdeck){
    srand(time(NULL));
    ivec stock(108);
    F(i,0,108)
        stock[i]=i;
    random_shuffle(stock.begin(),stock.end());
    for(int i=0;i<7;i++){
        pdeck.pb(stock[i]);
    }
    for(int i=7;i<14;i++){
        cdeck.pb(stock[i]);
    }
    stock.erase(stock.begin(),stock.begin()+14);
    return stock;
}
bool validinput(int index,ivec pdeck,string top,svec deck){
    //if(index>=pdeck.size() || index<-1)
        //return false;
    string s=deck[pdeck[index]];
    if(s.substr(0,1)=="5")
        return true;
    if(s[0]==top[0] || s.substr(1,s.size())==top.substr(1,top.size()))
        return true;
    return false;
}
char maxcol(ivec cdeck,svec deck){
    int arr[5]={0,0,0,0,0};
    F(i,0,cdeck.size()){
        if(deck[cdeck[i]][0]=='1')
            arr[0]+=1;
        if(deck[cdeck[i]][0]=='2')
            arr[1]+=1;
        if(deck[cdeck[i]][0]=='3')
            arr[2]+=1;
        if(deck[cdeck[i]][0]=='4')
            arr[3]+=1;
        if(deck[cdeck[i]][0]=='5')
            arr[4]+=1;
    }
    int max=*max_element(arr,arr+5);
    if(arr[0]==max)
        return '1';
    if(arr[1]==max)
        return '2';
    if(arr[2]==max)
        return '3';
    if(arr[3]==max)
        return '4';
    return '5';
}

tuple<int,string,ivec,ivec,ivec> p2c(int next,string top,ivec pdeck,ivec cdeck,svec deck,ivec stock){
    next=0;
    cout<<endl<<"Choose the index of your card you want to play:"<<endl;
    cout<<"If you don't have a suitable card and want to draw card from stock, input '-1'"<<endl;
    int index;
    cin>>index;
    cout<<endl;
    ivec samenum;
    ivec samecol;
    ivec power;
    F(i,0,cdeck.size()){
        string s=deck[cdeck[i]];
        if(s[0]==top[0] && s[0]!='5')
            samecol.pb(i);
        if(top.substr(1,top.size()-1)==s.substr(1,s.size()-1))
            samenum.pb(i);
        if(s[0]=='5')
            power.pb(i);
    }
    if(index==-1){
        int last=stock[0];
        pdeck.pb(stock[0]);
        stock.erase(stock.begin());
        string s=deck[last];
        if(s[0]==top[0] && s[0]!='5')
            samecol.pb(pdeck.size()-1);
        if(top.substr(1,top.size()-1)==s.substr(1,s.size()-1))
            samenum.pb(pdeck.size()-1);
        if(s[0]=='5')
            power.pb(pdeck.size()-1);
        /*
        if(samenum.size()==0 && samecol.size()==0 && power.size()==0){
            next=0;
            return make_tuple(next,top,pdeck,cdeck,stock);
        }*/
        cout<<endl;
        cout<<string(50,'=')<<endl;
        cout<<"Which card do you want to choose"<<endl;
        showtop(top,deck);
        showmine(top,deck,pdeck,cdeck);
        cout<<"If you can't play any card, input 'pass'"<<endl;
        cout<<"Choose card"<<endl;
        string rn;
        cin>>rn;
        if(rn =="pass" || rn == "Pass" || rn== "Pass"){
            next=0;
            return make_tuple(next,top,pdeck,cdeck,stock);
        }
        else{
            index=stoi(rn);
        }
    }
    if(validinput(index,pdeck,top,deck)==false){
        bool var=false;
        while(var==false){
            cout<<"Invalid input, try again."<<endl;
            cout<<"Choose the number of your card you want to play:"<<endl;
            cout<<"(Numbering starts from zero)"<<endl;
            cin>>index;
            var=validinput(index,pdeck,top,deck);
        }
    }

    top=deck[pdeck[index]];
    pdeck.erase(pdeck.begin()+index);
    if(top[0]=='5'){
        //showtop(top,deck);
        cout<<endl<<"To which colour do you want to change?"<<endl;
        cout<<"Red(r) /Blue(b) /Green(g) /Yellow(y)"<<endl;
        char color;
        cin>>color;
        if(color=='r'){
            top[0]='1';
        }
        if(color=='b'){
            top[0]='4';
        }
        if(color=='g'){
            top[0]='2';
        }
        if(color=='y'){
            top[0]='3';
        }
        if(top.size()==3){
            F(i,0,4)
                cdeck.pb(stock[i]);
            stock.erase(stock.begin(),stock.begin()+4);
            next=1;
            showtop(top,deck);
            return make_tuple(next,top,pdeck,cdeck,stock);
            exit;
        }
        showtop(top,deck);
    }
    else{
        if(top.size()==3){
            F(i,0,2)
                cdeck.pb(stock[i]);
            stock.erase(stock.begin(),stock.begin()+2);
            next=1;
            return make_tuple(next,top,pdeck,cdeck,stock);
            exit;
        }
        if(top.size()==2){
            showtop(top,deck);
            return make_tuple(next,top,pdeck,cdeck,stock);

        }
        else{
            next=1;
            return make_tuple(next,top,pdeck,cdeck,stock);
        }
    }
    return make_tuple(next,top,pdeck,cdeck,stock);
}

tuple<int,string,ivec,ivec,ivec> c2p(int next,string top,ivec pdeck,ivec cdeck,svec deck,ivec stock){
    ivec samecol;
    ivec samenum;
    ivec power;
    next=0;
    int val;
    F(i,0,cdeck.size()){
        string s=deck[cdeck[i]];
        if(s[0]==top[0] && s[0]!='5')
            samecol.pb(i);
        if(top.substr(1,top.size()-1)==s.substr(1,s.size()-1))
            samenum.pb(i);
        if(s[0]=='5')
            power.pb(i);
    }
    //baaaa
    //system("clear");
    if(samecol.size()==0 && samenum.size()==0){
        if(power.size()==0){
            cdeck.pb(stock[0]);
            stock.erase(stock.begin());
            cout<<"Computer took a card from stock"<<endl;
            return make_tuple(next,top,pdeck,cdeck,stock);
        }
        else{
            char changed=maxcol(cdeck,deck);
            if(deck[cdeck[power[0]]].size()==3){
                cdeck.erase(cdeck.begin()+power[0]);
                F(i,0,4)
                    pdeck.pb(stock[i]);
                stock.erase(stock.begin(),stock.begin()+4);
                F(i,0,cdeck.size()){
                    if(deck[cdeck[i]][0]==changed){
                        top=deck[cdeck[i]];
                        cdeck.erase(cdeck.begin()+i);
                        string tempo="5+4";
                        //cout<<"\033[1;3"<<top[0]<<"m"<<""<<"\033[0m";
                        cout<<endl<<"Computer played ";
                        printcard(tempo,deck);
                        cout<<":: changed the color to ";
                        if(top[0]=='1')
                            cout<<"\033[1;3"<<top[0]<<"m"<<"red"<<"\033[0m";
                        if(top[0]=='2')
                            cout<<"\033[1;3"<<top[0]<<"m"<<"green"<<"\033[0m";
                        if(top[0]=='3')
                            cout<<"\033[1;3"<<top[0]<<"m"<<"yellow"<<"\033[0m";
                        if(top[0]=='4')
                            cout<<"\033[1;3"<<top[0]<<"m"<<"blue"<<"\033[0m";
                        cout<<", and played a card."<<endl;
                        return make_tuple(next,top,pdeck,cdeck,stock);
                    }
                }
            }
            else{
                top="0Wild";
                top[0]=changed;
                cdeck.erase(cdeck.begin()+power[0]);
                cout<<endl<<"Computer played Wild, and changed color to ";
                if(top[0]=='1')
                    cout<<"\033[1;3"<<top[0]<<"m"<<"red"<<"\033[0m";
                if(top[0]=='2')
                    cout<<"\033[1;3"<<top[0]<<"m"<<"green"<<"\033[0m";
                if(top[0]=='3')
                    cout<<"\033[1;3"<<top[0]<<"m"<<"yellow"<<"\033[0m";
                if(top[0]=='4')
                    cout<<"\033[1;3"<<top[0]<<"m"<<"blue"<<"\033[0m";
                cout<<endl;
                return make_tuple(next,top,pdeck,cdeck,stock);
            }
        }
    }
    if(samenum.size()>samecol.size()){
        val=samenum[0];
        top=deck[cdeck[val]];
        cdeck.erase(cdeck.begin()+val);
        cout<<endl<<"Computer has played ";
        printcard(top,deck);
        cout<<endl;
        return make_tuple(next,top,pdeck,cdeck,stock);
    }
    if(samenum.size()<=samecol.size()){
        val=samecol[0];
        top=deck[cdeck[val]];
        cdeck.erase(cdeck.begin()+val);
        if(top.size()>2){//only for non numbers
            if(top.size()==3){//if +2
                F(i,0,2)
                    pdeck.pb(stock[i]);
                stock.erase(stock.begin(),stock.begin()+2);
                next=1;
                cout<<endl<<"Computer has played ";
                printcard(top,deck);
                cout<<endl;
                return make_tuple(next,top,pdeck,cdeck,stock);
            }
            else{//if skip or reverse
                next=1;
                cout<<endl<<"Computer has played ";
                printcard(top,deck);
                cout<<endl;
                return make_tuple(next,top,pdeck,cdeck,stock);
            }
        }
        cout<<endl<<"Computer has played ";
        printcard(top,deck);
        cout<<endl;
        return make_tuple(next,top,pdeck,cdeck,stock);
    }
    cout<<endl<<"Computer has played ";
    printcard(top,deck);
    cout<<endl;
    return make_tuple(next,top,pdeck,cdeck,stock);
}

int main(){
    system("clear");
    cout<<endl;
    cout<<"Welcome to UNO."<<endl;
    cout<<"The game starts off with 7 cards for each, and the aim is to drop all your cards"<<endl;
    cout<<endl;
    cout<<"Instructions:"<<endl;
    cout<<"The number in the middle top of each card is its index.";
    testcase();
    cout<<endl<<"In this case, the index of the card is 4, and to play that card, you must input 4 (when prompted)"<<endl;
    cout<<"--> For a card on top of a pile, you can drop any card which matches its color, or which matches its number, or any power (Wild or +4)"<<endl;
    cout<<"--> If you dont have any card which you can play, you can draw a card from the deck by entering -1 (when prompted)"<<endl;
    cout<<"--> If you still cant play any card, input 'pass'"<<endl;
    cout<<"Press ENTER to start"<<endl;
    svec deck=getdeck();
    ivec pdeck;
    ivec cdeck;
    ivec stock(108);
    F(i,0,108)
        stock[i]=i;
    srand(time(NULL));
    random_shuffle(stock.begin(),stock.end());
    F(i,0,7)
        pdeck.pb(stock[i]);
    F(i,7,14)
        cdeck.pb(stock[i]);
    stock.erase(stock.begin(),stock.begin()+14);

    if(cin.get()=='\n'){
        system("clear");
        int gameflag=0;
        int moves=0;
        string top;
        while(gameflag==0){
            if(moves==0)
                top=init(stock,deck);
            printall(top,deck,pdeck,cdeck);

            int next=0;

            tie(next,top,pdeck,cdeck,stock)=p2c(next,top,pdeck,cdeck,deck,stock);
            if(pdeck.size()==0 && cdeck.size()!=0){
                showcomp(top,deck,pdeck,cdeck);
                showtop(top,deck);
                cout<<endl<<"You won"<<endl;
                gameflag=1;
            }
            if(cdeck.size()==0 && pdeck.size()!=0){
                showtop(top,deck);
                showmine(top,deck,pdeck,cdeck);
                cout<<endl<<"You lost"<<endl;
                gameflag=1;
            }
            if(stock.size()==0){
                cout<<endl<<"Draw"<<endl;
                gameflag=1;
            }
            while(next==1){
                system("clear");
                cout<<endl<<"You get another turn"<<endl;
                printall(top,deck,pdeck,cdeck);
                tie(next,top,pdeck,cdeck,stock)=p2c(next,top,pdeck,cdeck,deck,stock);
            }
            system("clear");

            moves++;
            if(pdeck.size()==0 && cdeck.size()!=0){
                showcomp(top,deck,pdeck,cdeck);
                showtop(top,deck);
                cout<<endl<<"You won"<<endl;
                gameflag=1;
            }
            if(cdeck.size()==0 && pdeck.size()!=0){
                showtop(top,deck);
                showmine(top,deck,pdeck,cdeck);
                cout<<endl<<"You lost"<<endl;
                gameflag=1;
            }
            if(stock.size()==0){
                cout<<endl<<"Draw"<<endl;
                gameflag=1;
            }
            tie(next,top,pdeck,cdeck,stock)=c2p(next,top,pdeck,cdeck,deck,stock);
            if(pdeck.size()==0 && cdeck.size()!=0){
                showcomp(top,deck,pdeck,cdeck);
                showtop(top,deck);
                cout<<endl<<"You won"<<endl;
                gameflag=1;
            }
            if(cdeck.size()==0 && pdeck.size()!=0){
                showtop(top,deck);
                showmine(top,deck,pdeck,cdeck);
                cout<<endl<<"You lost"<<endl;
                gameflag=1;
            }
            if(stock.size()==0){
                cout<<endl<<"Draw"<<endl;
                gameflag=1;
            }
            while(next==1){
                cout<<endl<<"Computer gets another turn"<<endl;
                tie(next,top,pdeck,cdeck,stock)=c2p(next,top,pdeck,cdeck,deck,stock);
            }
            //system("clear");
            moves++;


            if(pdeck.size()==0 && cdeck.size()!=0){
                showcomp(top,deck,pdeck,cdeck);
                showtop(top,deck);
                cout<<endl<<"You won"<<endl;
                gameflag=1;
            }
            if(cdeck.size()==0 && pdeck.size()!=0){
                showtop(top,deck);
                showmine(top,deck,pdeck,cdeck);
                cout<<endl<<"You lost"<<endl;
                gameflag=1;
            }
            if(stock.size()==0){
                cout<<endl<<"Draw"<<endl;
                gameflag=1;
            }
        }
    }
}
