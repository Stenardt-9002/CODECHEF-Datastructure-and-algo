import java.util.*;
private static boolean check_prime(String order) 
{
    String[] split_order = order.split(" ", 3);
    try {
        Integer.parseInt(split_order[1]);
    } catch (NumberFormatException e) {
        return true;
    }
    return false;
}
public static List<String> sortOrders(List<String> orderList) 
{
        orderList.sort((firsst, second) -> {
            boolean firstprime = check_prime(firsst);
            boolean secondprime = check_prime(second);
            String[] splitstringfirst = firsst.split(" ", 2);
            String[] spltsecondstring = second.split(" ", 2);

            if(firstprime && secondprime) 
            {
                int relative1 = splitstringfirst[1].compareTo(spltsecondstring[1]);
                if(relative1 != 0)
                    return relative1;
                return splitstringfirst[0].compareTo(spltsecondstring[0]);
            }
            if(firstprime)
                return -1;
            if (secondprime)
                return 1;
            return 0;
        });

        return orderList;
}

// explaination 
// Since the prime metadata is non-numeric thus first check for prime metadata by checking it its possible to parse the first metadata part to Integer
// If integer(not prime) leave it as it is 
// if string(prime order )
//     check metadata comparsion (put lower one first)
//     if both metadata same 
//         compare alhanumeric id 
