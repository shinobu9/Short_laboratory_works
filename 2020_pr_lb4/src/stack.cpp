/*#include <string>
#include <iostream>
#include <cstring>
using namespace std;

typedef struct ListNode {
    ListNode* mNext;
    char* mData;
}ListNode;*/

class CustomStack {

public: // методы push, pop, size, empty, top + конструкторы, деструктор
	CustomStack(){
		mHead = new struct ListNode;
		mHead->mData = NULL;
		mHead->mNext = NULL;
		curSize = 0;
	}

	~CustomStack(){
		struct ListNode* mTmp = NULL;
		while(mHead->mNext){
			delete[] mHead->mData;
			mTmp = mHead;
			mHead = mHead->mNext;
			delete mTmp;
		}
		delete[] mHead->mData;
		delete mHead;
	}

	void push(const char* data){
		struct ListNode* mTmp = mHead;
		while(mTmp->mNext) // reach last element
			mTmp = mTmp->mNext;
		struct ListNode* newNode = new struct ListNode;
		newNode->mData = new char [strlen(data)+1];
		strcpy(newNode->mData, data);
		newNode->mNext = NULL;
		mTmp->mNext = newNode;
		curSize++;
	}

	void pop(){
		if(!isEmpty()){
			struct ListNode* mTmp = mHead;
			struct ListNode* mPrev = NULL;
			while(mTmp->mNext){ // reach last element
				mPrev = mTmp;
				mTmp = mTmp->mNext;
			}
			delete[] mTmp->mData;
			delete mTmp;
			curSize--;
			if(mPrev)
				mPrev->mNext = NULL;
		}
	}

	char* top(){
		if(isEmpty())
			return NULL;
		struct ListNode* mTmp = mHead;
		while(mTmp->mNext) // reach last element
			mTmp = mTmp->mNext;
		return mTmp->mData;
	}

	size_t size(){
		return curSize;
	}

	bool isEmpty(){
		return (curSize==0);
	}

private: // поля класса, к которым не должно быть доступа извне

protected: // в этом блоке должен быть указатель на голову
    struct ListNode* mHead;
    //ListNode* mTail;
    size_t curSize;
};


int main(){
	char text[3001];
    string line;
    getline(cin, line);
    strcpy(text, line.c_str());
	bool isCorrect = true;
	try{
		CustomStack stack;
		int i = 0;
		char* start = NULL;
		while(isCorrect && text[i]!='\0'){
			if(text[i] == '<'){
				start = text + i; // mark the start
			}
			if(text[i] == '>'){
				char temp = text[i+1];
				text[i+1] = '\0';
				if(strcmp(start, "<br>")!=0 && strcmp(start, "<hr>")!=0){ // not br hr
					if(start[1] == '/'){ // if closing tag
						char* lastTag = stack.top();
						if(!lastTag){
							isCorrect = false;							
							break;
						}
						if(!strcmp(&start[2], &lastTag[1])){
							stack.pop();
							start = NULL;
						}else{
							isCorrect = false;
						}
					}else{ // if opening tag
						stack.push(start);
					}
				}
				text[i+1] = temp;
			}
			i++;
		}

		if(!stack.isEmpty()){
			isCorrect=false;
		}
		if(isCorrect)
			cout << "correct" << endl;
		else
			cout << "wrong" << endl;
	}
	catch(bad_alloc& ex){
		cout << "Error: " << ex.what() << endl;
	}
	return 0;
}