class Solution {
public:
void setZeroes(vector<vector<int>> &matrix)
{
	vector<int> x,y;
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
		{
			if(matrix[i][j]==0)
			{
				x.push_back(i);
				y.push_back(j);
			}
		}
	}
	for(int i=0;i<x.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
		{
			matrix[x[i]][j]=0;
		}
	}
	for(int i=0;i<y.size();i++)
	{
		for(int j=0;j<matrix.size();j++)
		{
			matrix[j][y[i]]=0;
		}
	}
}
};