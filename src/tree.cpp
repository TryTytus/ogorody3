// Adam Tyton

#include "tree.hpp"
#include "branch.hpp"
#include "garden.hpp"

#define NULL 0


// CONSTRUCTOR

TREE_CLASS::TREE_CLASS() {
    CONSTRUCTOR(0, 0, NULL, NULL, NULL);
}


TREE_CLASS::TREE_CLASS(
        unsigned int treeID,
        unsigned int tHeight,
        TREE_CLASS* prev,
        TREE_CLASS* next,
        GARDEN_CLASS* parent
        ) {
    CONSTRUCTOR(
            treeID,
            tHeight,
            prev,
            next,
            parent
            );
}

void TREE_CLASS::CONSTRUCTOR(
        unsigned int treeID,
        unsigned int tHeight,
        TREE_CLASS *prev,
        TREE_CLASS *next,
        GARDEN_CLASS *parent
        ) {
    this->treeID = treeID;
    this->tHeight = tHeight;

    this->prev = prev;
    this->next = next;

    this->parent = parent;

    fNum = 0;
    bNum = 0;
    weight = 0;


    head = new BRANCH_CLASS(this, NULL, NULL);
    this->last = head;
    //head.CONSTRUCTOR();
}

// DESTRUCTOR

TREE_CLASS::~TREE_CLASS() {
    BRANCH_CLASS* cur = last;
    while (cur != head) {
        BRANCH_CLASS* prevCur = cur->getPrev();
        delete cur;
        cur = prevCur;
    }
    delete head;
}

// ------- GETTERS -------

unsigned int TREE_CLASS::getBranchesTotal() {
    return bNum;
}

unsigned int TREE_CLASS::getFruitsTotal() {
    return fNum;
}

unsigned int TREE_CLASS::getWeightsTotal() {
    return weight;
}

unsigned int TREE_CLASS::getNumber() {
    return treeID;
}

unsigned int TREE_CLASS::getHeight() {
    return tHeight;
}

GARDEN_CLASS* TREE_CLASS::getGardenPointer() {
    return parent;
}

BRANCH_CLASS* TREE_CLASS::getBranchPointer(unsigned int height) {
    BRANCH_CLASS* cur = head->getNext();
    while (cur != NULL)
    {
        if (cur->getHeight() == height) {
            return cur;
        }
        cur = cur->getNext();
    }
    return NULL;
}


// ------- SETTERS -------

void TREE_CLASS::growthTree() {
    BRANCH_CLASS* curF = head->getNext();
    bool exist = false;

    tHeight += 1;

    while (curF != NULL) {
        curF->growthBranch();
        if (curF->getLength() == tHeight)
        {
            exist = true;
        }

        curF = curF->getNext();
    }

    // STOP
    if (exist)
        return;

    // new Fruit

    if ((tHeight % 3 == 0) && (tHeight > 0))
    {
        BRANCH_CLASS* newBranch = new BRANCH_CLASS(
                this,
                NULL,
                NULL
                );
        pushBranch(newBranch);
    }

}

void TREE_CLASS::fadeTree() {
    // CHECK
    if (tHeight <= 0)
        return;

    BRANCH_CLASS* cur = head->getNext();

    tHeight -= 1;

    while (cur != NULL) {
        cur->fadeBranch();
        cur = cur->getNext();
    }

    if (last != head && tHeight < last->getHeight()) {
        BRANCH_CLASS* newLast = last->getPrev();
        delete last;

        last = newLast;
    }
}

void TREE_CLASS::harvestTree(unsigned int weightMax) {
    BRANCH_CLASS* cur = head->getNext();

    while (cur != NULL) {
        if (weightMax <= cur->getWeightsTotal()) {
            cur->fadeBranch();
        }
        cur = cur->getNext();
    }
}

void TREE_CLASS::cutTree(unsigned int cutTo) {

    BRANCH_CLASS* cur = last;

    unsigned int deletedB = 0;
    unsigned int deletedF = 0;
    unsigned int weightLost = 0;

    while (cur != head) {
        if (cutTo >= cur->getLength()) {
            break;
        }
        weightLost += cur->getWeightsTotal();
        deletedF += cur->getFruitsTotal();
        deletedB++;

        cur = cur->getPrev();
        delete cur->getNext();
    }

    cur->setPrev(NULL);
    last = cur;

    decFNum(deletedF);
    decFWeight(weightLost);
    decBNum(deletedB);
}

void TREE_CLASS::cloneBranch(BRANCH_CLASS *pBranch) {

}

// OTHER METHODS

void TREE_CLASS::decFWeight(unsigned int x) {
    weight -= x;
    if (parent != NULL)
        parent->decFWeight(x);
}

void TREE_CLASS::addFWeight(unsigned int x) {
    weight += x;
    if (parent != NULL)
        parent->addFWeight(x);
}

void TREE_CLASS::decFNum(unsigned int x) {
    fNum -= x;
    if (parent != NULL)
        parent->decFNum(x);
}

void TREE_CLASS::addFNum(unsigned int x) {
    fNum += x;
    if (parent != NULL)
        parent->addFNum(x);
}

void TREE_CLASS::decBNum(unsigned int x) {
    bNum -= x;
    if (parent != NULL)
        parent->decBNum(x);
}

void TREE_CLASS::addBNum(unsigned int x) {
    bNum += x;
    if (parent != NULL)
        parent->addBNum(x);
}

void TREE_CLASS::pushBranch(BRANCH_CLASS* pBranch) {
    pBranch->setPrev(last);
    last->setNext(pBranch);

    last = pBranch;

    addBNum(1);
}

void TREE_CLASS::popBranch() {
    if (last != head) {
        unsigned int fWeight = last->getWeightsTotal();
        unsigned int fNum = last->getFruitsTotal();

        BRANCH_CLASS* before = last->getPrev();
        before->setNext(NULL);

        delete last;
        last = before;

        decBNum(1);
        decFWeight(fWeight);
        decFNum(fNum);
    }
}


TREE_CLASS* TREE_CLASS::getPrev()
{
    return prev;
}

TREE_CLASS* TREE_CLASS::getNext()
{
    return next;
}

void TREE_CLASS::setPrev(TREE_CLASS* pTree)
{
    prev = pTree;
}
void TREE_CLASS::setNext(TREE_CLASS* pTree)
{
    next = pTree;
}