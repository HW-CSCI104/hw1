#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val) {
  if (tail_ == nullptr) {
    tail_ = new Item();
    head_ = tail_;
    head_->val[9] = val;
    head_->first = 9;
    head_->last = 10;
  } else {
    if (tail_->last == 10) {
      tail_->next = new Item();
      tail_->next->prev = tail_;
      tail_ = tail_->next;
      tail_->val[0] = val;
      tail_->first = 0;
      tail_->last = 1;
    } else {
      tail_->val[tail_->last] = val;
      tail_->last++;
    }
  }
  size_++;
}

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back() {
  if (empty()) {
    return;
  } else if (size_ == 1) {
    clear();
  } else {
    if (tail_->last == 1) {
      tail_ = tail_->prev;
      delete tail_->next;
      tail_->next = nullptr;
    } else {
      (tail_->last)--;
    }
    size_--;
  }
}
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void ULListStr::push_front(const std::string& val) {
  if (head_ == nullptr) {
    head_ = new Item();
    tail_ = head_;
    head_->val[0] = val;
    head_->first = 0;
    head_->last = 1;
  } else {
    if (head_->first == 0) {
      head_->prev = new Item();
      head_->prev->next = head_;
      head_ = head_->prev;
      head_->val[9] = val;
      head_->first = 9;
      head_->last = 10;
    } else {
      head_->val[(head_->first)-1] = val;
      (head_->first)--;
    }
  }
  size_++;
}

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front() {
  if (empty()) {
    return;
  } else if (size_ == 1) {
    clear();
  } else {
    if (head_->first == 9) {
      Item* temp = head_;
      head_ = head_->next;
      head_->prev = nullptr;
      delete temp;
    } else {
      head_->first++;
    }
    size_--;
  }
}
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const {
  return tail_->val[tail_->last-1];
}

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}
//STOP WRITING CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
  std::string* ULListStr::getValAtLoc(size_t loc) const {
    if (loc > size_) {
      return nullptr;
    }
    Item* temp = head_;
    while (temp != nullptr) {
      for (size_t i = temp->first; i < temp->last; i++) {
        if (loc == 0) {
          return &(temp->val[i]);
        }
        loc--;
      }
      temp = temp->next;
    }
    return nullptr;
  }
