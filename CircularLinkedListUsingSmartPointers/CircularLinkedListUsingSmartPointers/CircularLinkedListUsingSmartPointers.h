//
//  CircularLinkedListUsingSmartPointers.h
//  CircularLinkedListUsingSmartPointers
//
//  Created by Rohan Arora on 03/11/21.
//

#ifndef CircularLinkedListUsingSmartPointers_h
#define CircularLinkedListUsingSmartPointers_h

#include <memory>
#include <iostream>

namespace mylib {

template <typename T>
class List{
private:
    struct Node{
        T data;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;
        Node (T userdata);
    };
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
    size_t numberOfNodes{0};
    
public:
    //Appends the Data to the End of the List
    void append(T userData);
    
    //Checks whether the List is Empty .Returns True if the List is Empty.
    bool isEmpty() const;
    
    
    //Prints the List
    void print() const;
    
    //Clears the List
    void clear();
    
    
    /*Removes the Element at the Specified Position.Returns True if the Element is Removed or else
    returns false
     */
    bool removeAt(int pos);
    
};

template<typename T>
List<T>::Node::Node(T userData){
    data=userData;
    
}

template <typename T>
bool List<T>::isEmpty() const{
    if(head==nullptr and tail==nullptr){
        return true;
    }
    return false;
}



template <typename T>
void List<T>::append(T userData){
    std::shared_ptr<Node> temp = std::make_shared<Node>(userData);
    
    if(isEmpty()){
        head=temp;
        tail=head;
        numberOfNodes++;
    }
    else{
        //If we have only 1 node and we want to append data to it .
        if(head.get()==tail.get()){
            head->next=std::move(temp);
            head->prev=head->next;
            tail=head->next;
            tail->prev=head;
            tail->next=head;
            numberOfNodes++;
        }else{
            std::shared_ptr<Node> iterptr=head;
            while(iterptr!=tail){
                iterptr=iterptr->next;
            }
            iterptr->next=std::move(temp);
            tail=iterptr->next;
            tail->prev=iterptr;
            tail->next=head;
            head->prev=tail;
            numberOfNodes++;
        }
    }
}

template <typename T>
void List<T>::print() const{
    if(!isEmpty()){
    Node *iterptr=head.get();
    std::cout<<"Elements in the List are as Follows : "<<std::endl;
    std::cout<<iterptr->data<<std::endl;
   
    while(iterptr!=tail.get()){
        iterptr=iterptr->next.get();
        std::cout<<iterptr->data<<std::endl;
       
    }
    
    }else{
        std::cout<<"List is Empty "<<std::endl;
    }
    
}

template <typename T>
void List<T>::clear(){
    head.reset();
    tail.reset();
}


template <typename T>
bool List<T>::removeAt(int pos){
    if(isEmpty()){
        std::cout<<"List is Empty "<<std::endl;
        return false;
    }
    if(pos<0){
        std::cout<<"Position of Element cannot be Negative "<<std::endl;
        return false;
    }
    if(pos>=numberOfNodes){
        std::cout<<"Can't Remove an Element which is out of the List .\nWrong Position Entered "<<std::endl;
        return false;
    }
    //if the element to be removed is at pos 0
    if(pos==0){
        head->next->prev=tail;
        tail->prev=head->next;
        head=head->next;
        return true;
    }
    //If the element to be removed is at Last Position
    if(pos==numberOfNodes-1){
        tail->prev->next=head;
        head->prev=tail->prev;
        tail=tail->prev;
        return true;
    }else{
        //If the element is at some other Position
        std::shared_ptr<Node> iterPtr=head;
        int counter{0};
        while(counter!=pos){
            iterPtr=iterPtr->next;
            counter++;
        }
        iterPtr->next->prev=iterPtr->prev;
        iterPtr->prev->next=iterPtr->next;
        return true;
    }
    
    return false;
}



}




#endif /* CircularLinkedListUsingSmartPointers_h */
