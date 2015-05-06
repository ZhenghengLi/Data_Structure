template <class recType, int bTreeOrder>
void bTree<recType, bTreeOrder>::copyTree(bTreeNode<recType, bTreeOrder>* &copiedNode,
										  bTreeNode<recType, bTreeOrder>* otherNode
	)
{
	if(otherNode == NULL)
		copiedNode = NULL;
	else
	{
		copiedNode = new bTreeNode<recType, bTreeOrder>;
		for(int i = 0; i < otherNode->recCount ; i++)
			copiedNode->list[i] = otherNode->list[i];
		for(int i = 0; i <= otherNode->recCount; i++)
			copyTree(copiedNode->children[i], otherNode->children[i]);
	}
}
