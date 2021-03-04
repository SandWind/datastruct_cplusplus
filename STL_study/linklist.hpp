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
    
     Node *search(T searchdata){
        if (header) {
            if (header->vaule == searchdata) {
                return header;
            }
            Node *p = header->next;
            if (p) {
                while (p !=nullptr) {
                    if (p->vaule == searchdata) {
                        return p;
                    }
                    p = p ->next;
                }
            }
        }
        return nullptr;
    }
    
    bool deleteNode(T Deleatedata){
        Node *temp = nullptr;
        if (header) {
            if(header->vaule == Deleatedata){
                temp = header;
                header = header->next;
                delete temp;
                return  true;
            }
            else{
                Node *p = header->next;
                if (p->vaule == Deleatedata) {
                    temp = p;
                    header->next = p->next;
                    delete p;
                }
                else{
                    while (p->vaule != Deleatedata) {
                        
                        if (p->next->vaule == Deleatedata) {
                            temp = p->next;
                            p->next = p->next->next;
                            return  true;
                        }
                        else{
                            p = p->next;
                        }
                    }
                }
            }
            return true;
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
