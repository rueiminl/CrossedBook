#include "IBookManager.h"
#include "BookManager.h"
using namespace std;
shared_ptr<IBookManager> IBookManager::create() {
    return make_shared<BookManager>();
}
