
def solvteehm(board12,curx_pos,cury_pos,possiblemovx,possiblemovy,stecountp,n):
    if stecountp==(n*n):
        return True


    for ij1 in range(n):
        new_posx = curx_pos+possiblemovx[ij1];new_posy = cury_pos+possiblemovy[ij1];
        if (new_posx>=0 and new_posy>=0 and new_posx<n and new_posy<n and board12[new_posx][new_posy]==-2):
            #board not visited
            board12[new_posx][new_posy] = stecountp;#position to go
            if solvteehm(board12,new_posx,new_posy,possiblemovx,possiblemovy,stecountp+1,n):
                return True

            board12[new_posx][new_posy] = -2;




    return False




def main(n):
    #n is size of chess board
    board1 = [[-2 for i in range(n)] for j in range(n)]

    # 8x8 harcoded
    mov_ex1 = [2,1,-1,-2,-2,-1, 1, 2]
    mov_ey1 = [1,2, 2, 1,-1,-2,-2,-1]
    # print(board1)
    board1[0][0] = 0
    ste_pcnt = 1
    if solvteehm(board1,0,0,mov_ex1,mov_ey1,1,n)==False:
        print("No")

    print(board1)




if __name__ == '__main__':
    main(8)
