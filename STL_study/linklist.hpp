//
//  linklist.hpp
//  STL_study
//
//  Created by Ding Peng on 2021/3/4.
//

#ifndef linklist_hpp
#define linklist_hpp

#include <stdio.h>
template<typename T>
class listlist{
    struct Node{
        Node *next;
        T    vaule;
        Node(T data,Node *t=nullptr){
            vaule = data;
            next = t;
        }
    };
public:
    Node *header;
    
    bool invert(T newdata){
        if(header==nullptr){
            header = new Node(newdata);
        }
        else{
            Node *p = header->next;
            if(p==nullptr){
                header->next = new Node(newdata);
            }
            else{
                while(p!=nullptr){
                    if (p->next == nullptr) {
                        p->next = new Node(newdata);
                        return true;
                    }
                    else{
                        p = p->next;
                    }
                }
               
            }
            
        }
        return false;
    }
    
     bool search(T searchdata){
        if (header) {
            if (header->vaule == searchdata) {
                return true;
            }
            Node *p = header->next;
            if (p) {
                while (p !=nullptr) {
                    if (p->vaule == searchdata) {
                        return true;
                    }
                    p = p ->next;
                }
            }
        }
        return false;
    }
    ~listlist(){
        Node *tempNode = nullptr;
        if(header){
            while(header->next){
                tempNode = header->next;
                header->next = tempNode->next;
                delete tempNode;
            }
            delete header;
        }
    }
};
#endif /* linklist_hpp */
