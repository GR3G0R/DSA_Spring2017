//Gregory Delpe
//Assignment#5: Templated Hashtable With Linkedlist->BST Optimization
// FILE: hashtable.h
// TEMPLATE CLASS PROVIDED: Table<RecordType>
//   This class is a container template class for a Table of records.
//   The template parameter, RecordType, is the data type of the records in the
//   Table. It may any type with a default constructor, a copy constructor,
//   an assignment operator, and an integer member variable called key.
//
// CONSTRUCTOR for the Table<RecordType> template class:
//   Table( )
//     Postcondition: The Table has been initialized as an empty Table.
//
// MODIFICATION MEMBER FUNCTIONS for the Table<RecordType> class:
//   void insert(const RecordType& entry)
//     Precondition: entry.key >= 0. Also if entry.key is not already a key in
//     the table, then the Table has space for another record
//     (i.e., size( ) < CAPACITY).
//     Postcondition: If the table already had a record with a key equal to
//     entry.key, then that record is replaced by entry. Otherwise, entry has
//     been added as a new record of the Table.
//
//   void remove(int key)
//     Postcondition: If a record was in the Table with the specified key, then
//     that record has been removed; otherwise the table is unchanged.
//
// CONSTANT MEMBER FUNCTIONS for the Table<RecordType> class:
//   bool is_present(const Item& target) const
//     Postcondition: The return value is true if there is a record in the
//     Table with the specified key. Otherwise, the return value is false.
//
//   void find(int key, bool& found, RecordType& result) const
//     Postcondition: If a record is in the Table with the specified key, then
//     found is true and result is set to a copy of the record with that key.
//     Otherwise found is false and the result contains garbage.
//
//   size_t size( ) const
//     Postcondition: Return value is the total number of records in the
//     Table.
//
// VALUE SEMANTICS for the Table<RecordType> template class:
//   Assignments and the copy constructor may be used with Table objects.
//
// DYNAMIC MEMORY USAGE by the Table<RecordType> template class:
//   If there is insufficient dynamic memory, then the following functions
//   can call new_handler: the copy constructor, insert, the assignment
//   operator.

#ifndef TABLE2_H
#define TABLE2_H
#include <cstdlib>    // Provides size_t
#include <vector>
#include "node2.h"    // Provides the node type
#include "bintree.h"

namespace delpe_hashtable_h
{

    template<class RecordType>
    class LinkNode
    {
    public:
        int key;
        RecordType value;
        LinkNode* link_field;
        LinkNode* link() { return link_field; }
        void set_value(const RecordType& new_value) { value = new_value; }
        void set_link(LinkNode* new_link) { link_field = new_link; }
        LinkNode(int key, const RecordType& value)
        {
            this->key = key;
            this->value = value;
            this->link_field = NULL;
        }
    };

    template<class RecordType>
    class TreeNode
    {
    public:
        TreeNode(int key, RecordType value)
        {
            this->key = key;
            this->tree_node_value = value;
            left_child = NULL;
            right_child = NULL;
        }

        void add(int key, const RecordType& value)
        {
            if(value < this->tree_node_value)
            {
                if(left_child)
                    left_child->add(key, value);
                else
                    left_child = new TreeNode(key, value);
            }
            else if(this->tree_node_value < value)
            {
                if(right_child)
                    right_child->add(key, value);
                else
                    right_child = new TreeNode(key, value);
            }

        }

        bool contains(RecordType& value)
        {
            if(value < this->tree_node_value)
            {
                if(left_child)
                    return left_child->contains(value);
                else
                    return false;
            }
            else if(this->tree_node_value < value)
            {
                if(right_child)
                    return right_child->contains(value);
                else
                    return false;
            }
            else
            {
                return true;
            }

        }

        void set_value(const RecordType& new_value) { tree_node_value = new_value; }
        TreeNode* left() { return left_child; }
        TreeNode* right() { return right_child; }
        int get_key() { return key; }
        RecordType value() { return tree_node_value; }


    private:
        int key;
        RecordType tree_node_value;
        TreeNode *left_child, *right_child;
    };

    template <class RecordType>
    class HashTable
    {
    public:
        // MEMBER CONSTANT -- See Appendix E if this fails to compile.
        static const std::size_t TABLE_SIZE = 20;
        // CONSTRUCTORS AND DESTRUCTOR
        //HashTable();
        HashTable(const size_t& size = TABLE_SIZE); //Default size_t& size = TABLE_SIZE
        ~HashTable();
        // MODIFICATION MEMBER FUNCTIONS
        void put(int key, const RecordType& value);
        void put_tree(int key, const RecordType& value);
        void tree_put(int key, const RecordType& value);
        void preorder(TreeNode<RecordType>* root_ptr);
        void inorder(TreeNode<RecordType>* root_ptr);
        void postorder(TreeNode<RecordType>* root_ptr);
        int node_count(TreeNode<RecordType>* root_ptr) const;
        void display();
        void remove(int key);
        void remove_tree(int key);
        void rehash();
        int link_count(int key);
        void tree_clear(TreeNode<RecordType>*& root_ptr);
        void operator =(const HashTable& source);
        // CONSTANT MEMBER FUNCTIONS
        void get(int key);
        void get_tree(int key);
        void show_table();
        std::size_t size() const { return used; }
    private:
        std::size_t used;
        LinkNode<RecordType> **h_table;
        std::vector<TreeNode<RecordType>*> *htable;
        TreeNode<RecordType> **ht_table;
        double total_records;
        // HELPER MEMBER FUNCTION
        std::size_t hash(int key) const;
    };
}

#include "hashtable.template" // Include the implementation

#endif
