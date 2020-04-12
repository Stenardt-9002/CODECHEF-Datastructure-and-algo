
def pritboardwihoutpygame(board,size):
    for ij1 in range(size):
        for ki1 in range(size):
            if board[ij1][ki1]!=-1:
                print(board[ij1][ki1],end = ' ')
            else:
                print(" ",end = ' ')
        print()
    pass


if __name__ == '__main__':
    board = [[-1,-1,-1,2,6,-1,7,-1,1],[6,8,-1,-1,7,-1,-1,9,-1],[1,9,-1,-1,-1,4,5,-1,-1],[8,2,-1,1,-1,-1,-1,4,-1],[-1,-1,4,6,-1,2,9,-1,-1],[-1,5,-1,-1,-1,3,-1,2,8],[-1,-1,9,3,-1,-1,-1,7,4],[-1,4,-1,-1,5,-1,-1,3,6],[7,-1,3,-1,1,8,-1,-1,-1]]
    pritboardwihoutpygame(board,9)
    # main()
