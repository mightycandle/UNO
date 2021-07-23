#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
/**/
vector<string> vals={"0","1","2","3","4","5","6","7","8","9","Skip","Rev","+2","Wild","+4"};
vector<string> colors={"0","1","2","3","4","5"};
vector<string> cnames={"white","red","blue","green","yellow","magenta"};
vector<string> deck; // deck stores all 'cards'
vector<string> player;
vector<string> comp;
vector<string> pile;
vector<vector<int>> state;
int turn=0;

class Output{
	public:
	void print_possible(){ // for reference, prints your deck's split in color,number and power w.r.t pile's top card
		cout << "Same color : ";
		for(auto it=state[0].begin();it!=state[0].end();it++){
			cout << *it << ' ';
		}
		cout << "\n";
		cout << "Same num   : ";
		for(auto it=state[1].begin();it!=state[1].end();it++){
			cout << *it << ' ';
		}
		cout << "\n";
		cout << "Powers     : ";
		for(auto it=state[2].begin();it!=state[2].end();it++){
			cout << *it << ' ';
		}
		cout << "\n";
	}

	void print_card(string s){ // pretty print card
		if(s[0]=='2'){
			s[0]='4';
		}
		else if(s[0]=='3'){
			s[0]='2';
		}
		else if(s[0]=='4'){
			s[0]='3';
		}
		cout<<"\033[1;3"<<s[0]<<"m"<<s.substr(1,s.size()-1)<<"\033[0m"<<' ';
		// cout<<"\033[1;3"<<s[0]<<"m"<<s<<"\033[0m";
	}

	void print_top_card(){ // pretty print pile's top card
		string top=pile.back();
		cout<<"\n"<<"Top card of pile"<<"\n";
		cout<<string(8,'-')<<"\n";
		cout<<"|"<<string(6,' ')<<"|"<<"\n";
		cout<<"|"<<string(6,' ')<<"|"<<"\n";
		int y=top.size()-1;
		if(y==1 || y==2)
			cout<<"|  ";
		else
			cout<<"|"<<string(2-y%3,' ');
		print_card(top);
		if(y==1 || y==2)
			cout<<string(3-y,' ')<<"|   "<<"\n";
		else
			cout<<string(3-y+y%3,' ')<<"|   "<<"\n";
		cout<<"|"<<string(6,' ')<<"|"<<"\n";
		cout<<"|"<<string(6,' ')<<"|"<<"\n";
		cout<<string(8,'-')<<"\n"<<"\n";
	}

	void print_player(){ // pretty print player deck
		 cout<<"Your deck: "<<"\n";
		 for(int i=0;i<player.size();i++){
			if(i<10){
				cout<<string(3,'-')<<i<<string(4,'-')<<"  ";
			}
			else{
				cout<<string(3,'-')<<i<<string(3,'-')<<"  ";
			}
		}
		cout<<"\n";
		for(int i=0;i<player.size();i++)
			cout<<"|      |  ";
		cout<<"\n";
		for(int i=0;i<player.size();i++)
			cout<<"|      |  ";
		cout<<"\n";
		for(int i=0;i<player.size();i++){
			string x=player[i];
			int y=x.size()-1;
			if(y==1 || y==2){
				cout<<"|  ";
			}
			else{
				cout<<"|"<<string(2-y%3,' ');
			}
			print_card(player[i]);
			if(y==1 || y==2){
				cout<<string(3-y,' ')<<"|  ";
			}
			else{
				cout<<string(3-y+y%3,' ')<<"|  ";
			}
		}
		cout<<"\n";
		for(int i=0;i<player.size();i++)
			cout<<"|      |  ";
		cout<<"\n";
		for(int i=0;i<player.size();i++)
			cout<<"|      |  ";
		cout<<"\n";
		for(int i=0;i<player.size();i++)
			cout<<string(8,'-')<<"  ";
		cout<<"\n";
	}

	void print_comp(){ // pretty print computer's hidden deck
		cout<<"Computer's deck:"<<"\n";
		for(int i=0;i<comp.size();i++){
			if(i<10)
				cout<<string(3,'-')<<i<<string(4,'-')<<"  ";
			else
				cout<<string(3,'-')<<i<<string(3,'-')<<"  ";
		}
		cout<<"\n";
		for(int i=0;i<comp.size();i++)
			cout<<"|      |  ";
		cout<<"\n";
		for(int i=0;i<comp.size();i++)
			cout<<"|  ?   |  ";
		cout<<"\n";
		for(int i=0;i<comp.size();i++)
			cout<<"|      |  ";
		cout<<"\n";
		for(int i=0;i<comp.size();i++)
			cout<<string(8,'-')<<"  ";
		cout<<"\n";
	}

	void show_comp(){ // just to debug, reveals computer deck
		cout<<"Computer's deck:"<<"\n";
		for(int i=0;i<comp.size();i++){
			if(i<10)
				cout<<string(3,'-')<<i<<string(4,'-')<<"  ";
			else
				cout<<string(3,'-')<<i<<string(3,'-')<<"  ";
		}
		cout<<"\n";
		for(int i=0;i<comp.size();i++)
			cout<<"|      |  ";
		cout<<"\n";
		for(int i=0;i<comp.size();i++)
			cout<<"|      |  ";
		cout<<"\n";
		for(int i=0;i<comp.size();i++){
			string x=comp[i];
			int y=x.size()-1;
			if(y==1 || y==2)
				cout<<"|  ";
			else
				cout<<"|"<<string(2-y%3,' ');
			print_card(comp[i]);
			if(y==1 || y==2)
				cout<<string(3-y,' ')<<"|  ";
			else
				cout<<string(3-y+y%3,' ')<<"|  ";
		}
		cout<<"\n";
		for(int i=0;i<comp.size();i++)
			cout<<"|      |  ";
		cout<<"\n";
		for(int i=0;i<comp.size();i++)
			cout<<"|      |  ";
		cout<<"\n";
		for(int i=0;i<comp.size();i++)
			cout<<string(8,'-')<<"  ";
		cout<<"\n";

	}
}out;

void make_deck(){
	// except wild,+4,0 all deck occurs 8 times - twice each in r,b,g,y
	// denoting the colors of the deck - 1,2,3,4
	for(int i=0;i<13;i++){
		for(int j=1;j<=4;j++){
			deck.push_back(colors[j]+vals[i]);
			if(i!=0){
				deck.push_back(colors[j]+vals[i]);
			}
		}
	}
	for(int i=13;i<=14;i++){
		for(int j=0;j<4;j++){
			deck.push_back(colors[5]+vals[i]);
		}
	}
	vector<int> stock; // stock stores 'indices' of the cards in deck
	for(int i=0;i<108;i++){
		stock.push_back(i);
	}
	// shuffling order of cards in stock
	random_shuffle(stock.begin(),stock.end());
	// now to adjust the actual cards arrangement w.r.t. the stock's arrangement
	vector<string> dummy;
	for(int i=0;i<108;i++){
		dummy.push_back(deck[stock[i]]);
	}
	deck=dummy;
}

void split_cards(){
	// removing 14 cards from stock and assigning 7 each to player & computer
	for(int i=0;i<7;i++){
		player.push_back(deck.back());
		deck.pop_back();

		comp.push_back(deck.back());
		deck.pop_back();
	}
}

void get_pile(){
	int idx=0;
	for(int i=0;i<deck.size();i++){
		if(deck[i].substr(0,1)=="5"){
			continue;
		}
		if(deck[i].size()==2){
			idx=i;
			break;
		}
	}
	pile={deck[idx]};
	deck.erase(deck.begin()+idx);
}

int game_over(){
	bool b1=player.empty(); // b1 is 1 if player dropped all his cards
	bool b2=comp.empty();   // b2 is 1 if comp dropped all its cards
	if(b1^b2){ // if b1 is 0 & b2 is not and vice versa
		if(b1){
			cout << "Computer wins!" << "\n";
			return 2; // computer wins
		}
		else{
			cout << "Player wins" << "\n";
			return 1; // player wins
		}
	}
	if(deck.empty()){ // if deck is empty, it's a draw
		cout << "It's a draw!" << "\n";
		return 3; // draw
	}
	return 0; // nothing happened. just continue playing.
}

void get_move(vector<string> current){
	string top=pile.back();
	string topcol=top.substr(0,1);
	string topnum=top.substr(1,top.size()-1);
	// topcol is color of top card of pile
	// topnum is number of top card of pile

	vector<int> same_num; // stores indices of current's cards whose number is topnum
	vector<int> same_col; // stores indices of current's cards whose color is topcol
	vector<int> powers; // store indices of powers if any
	for(int i=0;i<current.size();i++){
		string x=current[i];
		if(x[0]==topcol[0]){
			same_col.push_back(i);
		}
		else if(x.substr(1,x.size()-1)==topnum && x[0]!='5'){
			same_num.push_back(i);
		}
		else if(x[0]=='5'){
			powers.push_back(i);
		}
	}
	state.clear();
	// state is a vector of vector string that contains:
	state.push_back(same_col);
	state.push_back(same_num);
	state.push_back(powers);
}

bool valid(int idx){ 
	// checks if the user's index input is valid
	if(idx==-1){
		return 1;
	}
	for(auto x:state){
		for(auto y:x){
			if(y==idx){
				return 1;
			}
		}
	}
	return 0;
}

int max_color(){
	// finds the color with maxmimum occurences in computer's deck
	if(comp.empty()){
		return 0;
	}
	vector<int> freq(5);
	for(int i=0;i<comp.size();i++){
		freq[comp[i][0]-'0']++;
	}
	int idx=max_element(freq.begin(),freq.end())-freq.begin();
	if(idx==0 || idx==5)idx=1;
	return idx;
}

int is_non_num(string card){
	// 0 is a normal number
	// 1 is skip/reverse
	// 2 is +2
	// 3 is wild
	// 4 is +4
	int cardlen=card.size();
	if(cardlen==2){
		return 0;
	}
	if(card[0]=='5'){
		if(cardlen==5){
			return 3;
		}
		return 4;
	}
	if(card.back()=='2'){
		return 2;
	}
	return 1;
}

class Game{
	public:
	void player_to_comp(bool again=0){ // again is 1 if the player played skip/reverse
		get_move(player);
		out.print_possible();
		cout << "\nEnter the index of the card you wanna drop";
		cout << "\nDraw a card from the stock by typing '-1' and press enter\n";
		int idx;
		string input;
		cin >> input;
		if(input=="pass"){
			idx=-2;
		}
		else{
			idx=stoi(input);
		}
		while(!valid(idx) && input!="pass"){
			cout << "Enter a valid input" << "\n";
			cin >> input;
			if(input=="pass"){
				break;
			}
			idx=stoi(input);
			if(idx==-1 && again){
				idx=-2;
			}
		}
		if(idx==-1){
			player.push_back(deck.back());
			deck.pop_back();

			cout << "\n\n";
			out.show_comp();
			out.print_top_card();
			out.print_player();


			get_move(player);
			idx=player.size()-1;
			cout << "If you can't make a move, type 'pass' and hit enter.\n";
			cout << "Else, enter the index of the card that you can drop" << "\n";
			idx=-2;
			while(!valid(idx)){
				string r;
				cin >> r;
				if(r=="pass"){
					idx=-2;
					break;
				}
				if(r=="-1"){
					idx=-2;
					break;
				}
				idx=stoi(r);
			}
		}
		if(idx==-2){
			return;
		}
		cout << "You played ";
		out.print_card(player[idx]);
		cout << "\n";
		string card=player[idx];
		pile.push_back(player[idx]);
		player.erase(player.begin()+idx);
		int move=is_non_num(card);
		if(!move){
			return;
		}
		if(move%2==0){ // +2 or +4
			for(int i=0;i<move;i++){
				comp.push_back(deck.back());
				deck.pop_back();
			}
		}
		if(move==4 || move==3){ // wild or a +4
			cout << "Enter the color you want to switch to\n";
			cout << "Red(r) / Blue(b) / Green(g) / Yellow(y)\n";
			char c;
			cin >> c;
			string new_card=card;
			if(c=='r'){
				new_card[0]='1';
			}
			else if(c=='b'){
				new_card[0]='2';				
			}
			else if(c=='g'){
				new_card[0]='3';				
			}
			else if(c=='y'){
				new_card[0]='4';				
			}
			pile.push_back(new_card);
		}
		if(move==1){ // skip or reverse
			get_move(player);
			out.print_player();
			player_to_comp(1);	// recurse with variable again=1
		}
	}

	void comp_to_player(bool again=0){
		get_move(comp);
		// out.print_possible();
		bool change=0,done=0;

		bool b0=state[0].empty();
		bool b1=state[1].empty();
		bool b2=state[2].empty();

		int first=-1;
		int second=-1;

		if(!b1){
			second=state[1][0];
		}
		bool same_color_number=0;
		if(!b0){
			for(int i=0;i<state[0].size();i++){
				if(comp[state[0][i]].size()==2){
					first=state[0][i];
					same_color_number=1;
					break;
				}
				else{
					first=state[0][i];
				}
			}
		}
		// First priority is given to a number of same color
		// Then to the number of different color
		// And then to the power cards of the same color / wild or +4
		int idx=-1;
		if(first!=-1 && same_color_number){
			idx=first;
		}
		else if(second!=-1){
			idx=second;
		}
		else if(first!=-1 && !same_color_number){
			idx=first;
		}
		if(idx==-1){
			if(!b2){
				idx=state[2][0];
			}
		}

		if(idx==-1 && !again){ // if there's no valid move, take card from deck
			comp.push_back(deck.back());
			deck.pop_back();
			idx=comp.size()-1;
			get_move(comp);
			int done=-1;
			for(auto x:state){
				for(auto y:x){
					if(y==idx){
						done=1;
					}
				}
			}
			if(done==-1){
				idx=-1;
			}
		}

		if(idx==-1){ // if still no valid move, leave
			cout << "Computer has drawn a card, and has no valid move.\n";
			return;
		}
		
		// the final move (the card's index) is stored in idx
		cout << "Computer played ";
		out.print_card(comp[idx]);
		cout << "\n";
		string card=comp[idx];
		pile.push_back(comp[idx]);
		comp.erase(comp.begin()+idx);
		int move=is_non_num(card);
		if(!move){
			return;
		}
		if(move%2==0){ // +2 or +4
			for(int i=0;i<move;i++){
				player.push_back(deck.back());
				deck.pop_back();
			}
		}
		if(move==4 || move==3){
			// cout << "Enter the color you want to switch to\n";
			// cout << "Red(r) / Blue(b) / Green(g) / Yellow(y)\n";
			int which_index=max_color();
			if(max_color==0){
				return;
			}
			char c=cnames[which_index][0];
			string new_card=card;
			cout << "Computer changed the color to ";
			if(c=='r'){
				new_card[0]='1';
				out.print_card("1red");
			}
			else if(c=='b'){
				new_card[0]='2';
				out.print_card("2blue");
			}
			else if(c=='g'){
				new_card[0]='3';
				out.print_card("3green");		
			}
			else if(c=='y'){
				new_card[0]='4';
				out.print_card("4yellow");
			}
			pile.push_back(new_card);
		}
		if(move==1){
			comp_to_player(1);	
		}
	}
}g;



void display();
int main(){
	srand(time(NULL));
	make_deck();
	split_cards();
	get_pile();

	system("clear");
	display();
	int moves=0;
	if(cin.get()=='\n'){
		system("clear");
		while(!game_over()){
			cout << "\n\n";
			out.show_comp();
			out.print_top_card();
			out.print_player();
			if(turn==0){
				cout << "\n====PLAYER TO COMPUTER===\n";
				g.player_to_comp();
			}
			else{
				system("clear");
				cout << "\n====COMPUTER TO PLAYER===\n";
				g.comp_to_player();
			}
			turn^=1;
		}
	}

	return 0;
}
void display(){
	cout<<"\nWelcome to UNO.\n";
    cout<<"The game starts off with 7 deck for each, and the aim is to drop all your deck\n";
    cout<<"\nInstructions:\nThe number in the middle top of each card is its index.";
    string top="35";
    cout<<"\n"<<"Example:"<<"\n";
    cout<<string(6,' ')<<string(3,'-')<<"4"<<string(4,'-')<<"\n";
    cout<<string(6,' ')<<"|"<<string(6,' ')<<"|"<<"\n";
    cout<<string(6,' ')<<"|"<<string(6,' ')<<"|"<<"\n";
    int y=top.size()-1;
    cout<<string(6,' ')<<"|  ";
    cout<<"\033[1;3"<<top[0]<<"m"<<top.substr(1,top.size()-1)<<"\033[0m";
    cout<<string(4-y,' ')<<"|   "<<"\n";
    cout<<string(6,' ')<<"|"<<string(6,' ')<<"|\n";
    cout<<string(6,' ')<<"|"<<string(6,' ')<<"|\n";
    cout<<string(6,' ')<<string(8,'-')<<"\n";
    cout<<"\nIn this case, the index of the card is 4, and to play that card, you must input 4 (when prompted)\n";
    cout<<"--> For a card on top of a pile, you can drop any card which matches its color, or which matches its number, or any power (Wild or +4)\n";
    cout<<"--> If you dont have any card which you can play, you can draw a card from the deck by entering -1 (when prompted)\n";
    cout<<"--> If you still cant play any card, input 'pass'\n";
    cout<<"Press ENTER to start\n";
}