template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::destroyTree()
{
	if(root != NULL)
	{
		destroy(root);
		delete root;
		root = NULL;
	}
}

template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::destroy(bTreeNode<recType, bTreeOrder>* current)
{
	if(current != NULL)
	{
		for(int i = 0; i <= current->recCount; i++)
		{
			destroy(current->children[i]);
			delete current->children[i];
			current->children[i] = NULL;
		}
	}
}
