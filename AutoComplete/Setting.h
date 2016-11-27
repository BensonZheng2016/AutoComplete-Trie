#ifndef Setting_H
#define Setting_H
#include <Windows.h>
#include <shellapi.h>
#include <WinUser.h>
#include <iostream>
#include "Trie.h"
#include <stack>
#include <vector>
using namespace std;
CTrie dic;

bool flag = true;//co phai nhap tu moi hay khong?
vector<string> collect;
string input;
stack<CTrie_Node*> posStack;
string word;
CTrie_Node* posTrieNode = NULL;

POINT pos;
INPUT inputKeyboard;
bool capslockState = false;
void XuatKey(WORD key);
void XuatString(string key);
void XuatChar(char tmp);
void xuat(string input);
bool garbageChar(int key);
#endif