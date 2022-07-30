firstRep(s)
{
    //code here
    let arrayindx = new Array(256);
    for(let i=0;i<26 ; i++)
        arrayindx[i] = 0 ;

    for(let i=0;i<s.length ; i++)
        arrayindx[str[i].charCodeAt()]++ ;

    for(let i=0;i<s.length ; i++)
        if(arrayindx[str[i].charCodeAt()]>1) 
            return str[i];

    return '#';
    

}

