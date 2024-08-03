#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<fstream>
#include<iostream>
#include<queue>
#define MAX1 1000000005
#define MAX2 200005
#define MAX3 100005
//#include<conio.h>
using namespace std;
fstream gml("games.cfg",ios::in);
struct game{
	char name[50];
	int ver[4];
	char a[100];
	string b;
};
game g[100];
int n;
int main(){
	gml>>n;
	system("echo off & cls");
	system("title stead_game_centre");
	if(n>1)printf("%d games loaded\n",n);
	else printf("%d game loaded\n",n);
	system("pause");
	for(int i = 0;i<n;i++){
		gml>>g[i].name;
		gml>>g[i].ver[0]>>g[i].ver[1]>>g[i].ver[2]>>g[i].ver[3];
		gml>>g[i].a>>g[i].b;
		printf("========game%3d========\n",i);
		cout<<g[i].name<<"\n";
		printf("ver%d.%d.%d.%d\n",g[i].ver[0],g[i].ver[1],g[i].ver[2],g[i].ver[3]);
		cout<<g[i].a<<"\n";
	}
	cout<<"=======================\n";
	while(1>0){
		int t;
		cin>>t;
		if(g[t].b==""){
			cout<<"GAME NOT FOUND!\n";
			continue;
		}
		int i = t;
		printf("========game%3d========\n",i);
		cout<<g[i].name<<"\n";
		printf("ver%d.%d.%d.%d\n",g[i].ver[0],g[i].ver[1],g[i].ver[2],g[i].ver[3]);
		cout<<g[i].a<<"\n";
		cout<<"=======================\n";
		string c ="start "+g[i].b+" NORMAL MAX";
		int w = system(c.c_str());
		printf("return = %d\n",w);
	}
	return 0;
}

