#include <iostream>

using namespace std;

int score[4]={0,0,0,0};// win=0,loose=0,tie=0,game=0;
void center(string);
char yesNo(string);
string makeCol(string,string,char,int,int=-1);
int rps();
void scorep();

int main(){
 string picture[3][7]={{"        __---__          ","     _--       ---__     ","    /               \\_   ","   |                  )  ","   \\                 /   ","    \\              _/    ","     ---________---      "},{"     ---__            __-","    /     ---____-----  /","   /                   / ","  /                   /  "," /                   /   "," -___               /    ","     ---________---/     "},{"      __        __       ","     /  \\      / /       ","     \\__/\\   / /         ","        \\ \\/ /           ","    __   /\\ \\            ","   /  \\/_/  \\ \\          ","   \\__/       \\_\\        "}};
 unsigned int seed=time(0);
 srand(seed);
 char a1;
 int x,y,play;
 string rpsa[3]={"rock","paper","scissors"},text;
 a1=yesNo("Wanna play rock paper scissors? y/n: ");
 while(a1=='y'){
  scorep();
  x=rand()%3;
  play=rps();
  if(play==x){
   text="Oop, it's a tie! We both played "+rpsa[x]+"\n";
   center(text);
   score[2]++;}
  else if(play==x+ 1||play==x- 2){
   text="You win! "+rpsa[play]+" beats "+rpsa[x]+"\n";
   center(text);
   score[0]++;}
  else{
   text="I win! "+rpsa[x]+" beats "+rpsa[play]+"\n";
   center(text);
   score[1]++;}
  for(int i=0;i<7;i++){
   cout<<picture[x][i]<<"  ";
   for(int j=24;j>=0;j--){
    if(picture[play][i][j]=='\\')cout<<'/';
    else if(picture[play][i][j]=='/')cout<<'\\';
    else if(picture[play][i][j]==')')cout<<'(';
    else cout<<picture[play][i][j];}
   cout<<"\n";
  }
  cout<<"\n";
  score[3]++;
  a1=yesNo("Play Again? y/n: ");}//rps
 scorep();
 cout<<"\n";
 center("I had fun, Goodbye\n");
 return 0;}
char yesNo(string text){
 char ans='0';
 string trash;
 while(ans!='y'&&ans!='n'){
  center(text);
  cin>>ans;
  cout<<"\n";
  getline(cin,trash);
  ans=tolower(ans);}
 std::cout<<u8"\033[2J\033[1;1H";
 return ans;}
int rps(){
 string ans="",trash;
 int results;
 while(ans!="rock"&&ans!="paper"&&ans!="scissors"){
  cout<<"\n";
  center("Enter your choice: rock, paper or scissors: ");
  cin>>ans;
  getline(cin,trash);
  for(int i=0;ans[i];i++)
   ans[i]=tolower(ans[i]);}
  if(ans=="rock")return 0;
  if(ans=="paper")return 1;
  else return 2;}

void scorep(){
 cout<<"       _____________________________________\n       |  Wins  | Losses |  Ties  |  Total |\n       |________|________|________|________|\n       |";
 string num,text;
 int width, i;
 for(int x=0;x<4;x++){
  width=8;
  num=to_string(score[x]);
  width-=num.length();
  for(i=0;i<(width/2);i++)
   text+=' ';
  text+=num;
  for(i;i<width;i++)
   text+=' ';
  text+='|';
 }
 cout<<text<<"\n       |________|________|________|________|";
 return;}

void center(string text){
 int i=26 - text.length()/2;
 for(i;i>0;i--)
  cout<<" ";
 cout<<text;
 return;}
 
 

