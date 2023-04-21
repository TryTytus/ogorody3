// Adam Tyton

#include "garden.hpp"
#include "tree.hpp"

#define NULL 0


// CONSTRUCTOR

GARDEN_CLASS::GARDEN_CLASS() {
    CONSTRUCTOR();
}

void GARDEN_CLASS::CONSTRUCTOR() {
    tLastID = 0;
    tNum = 0;
    bNum = 0;
    cuted = 0;

    fNum = 0;
    fWeight = 0;

    head = new TREE_CLASS(0, 0, NULL, NULL, this); // TREE_CLASS(0, 0, NULL, NULL, this);
    // head->CONSTRUCTOR(0, 0, NULL, NULL, this);
    last = head;
}

GARDEN_CLASS::~GARDEN_CLASS() {
    TREE_CLASS* cur = last;
    while (cur != head) {
        TREE_CLASS* prevCur = cur->getPrev();
        delete cur;
        cur = prevCur;
    }
    delete head;
}

// ------- GETTERS -------

unsigned int GARDEN_CLASS::getTreesTotal() {
    return tNum;
}

unsigned int GARDEN_CLASS::getBranchesTotal() {
    return bNum;
}

unsigned int GARDEN_CLASS::getFruitsTotal() {
    return fNum;
}

unsigned int GARDEN_CLASS::getWeightsTotal() {
    return fWeight;
}


TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int treeID)
{
        TREE_CLASS* cur = head->getNext();
        while (cur != NULL )
        {
            if (treeID == cur->getNumber())
            {
                return cur;
            }
            cur = cur->getNext();
        }
        return NULL;
}

// ------- SETTERS -------

void GARDEN_CLASS::plantTree()
{
    if (tNum == 0)
        pushTree(
                new TREE_CLASS(
                        0,
                        0,
                        NULL,
                        NULL,
                        this
                ));
    else if (cuted == 0) {
        pushTree(
            new TREE_CLASS(
                last->getNumber() + 1,
                0,
                NULL,
                NULL,
                this
            ));
    } else {
        TREE_CLASS* cur = head->getNext();
        unsigned int exp = 0;
        while (cur != NULL) {
            if (cur->getNumber() != exp)
            {
                break;
            }
            exp++;
            cur = cur->getNext();
        } 
            pushTree(
            new TREE_CLASS(
                exp,
                0,
                NULL,
                NULL,
                this
            ));
            cuted--;
    }
}
void GARDEN_CLASS::extractTree(unsigned int treeID)
{
    TREE_CLASS* cur = head->getNext();
    while (cur != NULL )
    {
        if (treeID == cur->getNumber())
        {
            TREE_CLASS* before = cur->getPrev();
            TREE_CLASS* after = cur->getNext();

            unsigned int fWeight = cur->getWeightsTotal();
            unsigned int fNum = cur->getFruitsTotal();
            unsigned int bNum = cur->getBranchesTotal();

            before->setNext(after);

            if (after != NULL)
            {
                after->setPrev(before);
            }

            delete cur;

            decTNum(1);
            decBNum(bNum);
            decFWeight(fWeight);
            decFNum(fNum);
            
            cuted++;

            return;
        }
        cur = cur->getNext();
    }
    

}
void GARDEN_CLASS::cloneTree(unsigned int treeID)
{
    
}

void GARDEN_CLASS::growthGarden()
{
    TREE_CLASS* cur = head->getNext();

    while (cur != NULL) {
        cur->growthTree();
        cur = cur->getNext();
    }
}

void GARDEN_CLASS::fadeGarden()
{
    TREE_CLASS* cur = head->getNext();

    while (cur != NULL) {
        cur->fadeTree();
        cur = cur->getNext();
    }

}


void GARDEN_CLASS::harvestGarden(unsigned int weight)
{
    TREE_CLASS* cur = head->getNext();

    while (cur != NULL) {
        cur->harvestTree(weight);
        cur = cur->getNext();
    }

}

void GARDEN_CLASS::decFWeight(unsigned int x) {
    fWeight -= x;
}

void GARDEN_CLASS::addFWeight(unsigned int x) {
    fWeight += x;
}

void GARDEN_CLASS::decFNum(unsigned int x) {
    fNum -= x;
}

void GARDEN_CLASS::addFNum(unsigned int x) {
    fNum += x;
}

void GARDEN_CLASS::decBNum(unsigned int x) {
    bNum -= x;
}

void GARDEN_CLASS::addBNum(unsigned int x) {
    bNum += x;
}

void GARDEN_CLASS::decTNum(unsigned int x) {
    tNum -= x;
}

void GARDEN_CLASS::addTNum(unsigned int x) {
    tNum += x;
}


void GARDEN_CLASS::pushTree(TREE_CLASS* pTree) {
    pTree->setPrev(last);
    last->setNext(pTree);

    last = pTree;

    addTNum(1);
}

void GARDEN_CLASS::popTree() {
    if (last != head) {
        unsigned int fWeight = last->getWeightsTotal();
        unsigned int fNum = last->getFruitsTotal();
        unsigned int bNum = last->getBranchesTotal();

        TREE_CLASS* before = last->getPrev();
        before->setNext(NULL);

        delete last;
        last = before;

        decTNum(1);
        decBNum(bNum);
        decFWeight(fWeight);
        decFNum(fNum);
    }
}
