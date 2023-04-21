// Adam Tyton

class BRANCH_CLASS;

class FRUIT_CLASS {
private:
        unsigned int weight;
        unsigned int len;

        BRANCH_CLASS* parent;
        bool isHead;

        FRUIT_CLASS *prev;
        FRUIT_CLASS *next;

public:

        // CONSTRUCTOR

        FRUIT_CLASS();

        FRUIT_CLASS(
                BRANCH_CLASS* parent,
                FRUIT_CLASS *prev,
                FRUIT_CLASS *next,
                unsigned int bLenght
        );

        void CONSTRUCTOR(
                BRANCH_CLASS* parent,
                FRUIT_CLASS* prev,
                FRUIT_CLASS* next,
                unsigned int bLenght
                );


        // GETTERS
        unsigned int getLength();
        unsigned int getWeight();

        BRANCH_CLASS *getBranchPointer();

        // SETTERS
        void growthFruit();
        void fadeFruit();
        void pluckFruit();

        // OTHER METHODS

        void decFWeight(unsigned int x);
        void addFWeight(unsigned int x);

        FRUIT_CLASS* getPrev();
        FRUIT_CLASS* getNext();

        void setPrev(FRUIT_CLASS* pFruit);
        void setNext(FRUIT_CLASS* pFruit);

        void setLength(unsigned int bLength);
};