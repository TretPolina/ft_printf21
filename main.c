#include <stdio.h>
#include "includes/ft_printf.h"
int main(void)
{
	/****************Integer****************/

	/* printf("%+d.\n", 1234567);
	printf("%-d.\n", 1234567);
	printf("% d.\n", 1234567);
	printf("%0d.\n", 1234567);
	//printf("%#d.\n", 1234567);
	printf("%+012d.\n", 1234567);
	printf("%12.15d.\n", 1234567);
	printf("%d.\n", 1234567);
	printf("%d.\n", 1234567); */

	//ft_printf("%5d", 10);
    /* printf("%d", +0);
    ft_printf("%d", -0);
    printf("%d", -0); */
    /* 
    without equal
    pwl-pd
    plw-pd

    wpl-wpd
    wlp-wd

    lwp-d
    lpw-d

    ***********************
    with minus

    pwl-pd
    plw-pd

    wpl-pdw
    wlp-dw

    lwp-d
    lpw-d
    ***********************
    with equal


    ***********************
    with equal with minus

    
    */
	/* printf("\n**********without equal*********\n\n");
    printf("pwl %10.12d.\n", 1234567);//pwl
    printf("plw %5.12d.\n", 1234567);//plw

    printf("wpl %10.8d.\n", 1234567);//wpl
    printf("wlp %10.2d.\n", 1234567);//wlp
    
    printf("lwp %5.2d.\n", 1234567);//lwp
    printf("lpw %2.5d.\n", 1234567);//lpw

    printf("\n**********without equal, with minus*********\n\n");

    printf("pwl %-10.12d.\n", 1234567);//pwl
    printf("plw %-5.12d.\n", 1234567);//plw

    printf("wpl %-10.8d.\n", 1234567);//wpl
    printf("wlp %-10.2d.\n", 1234567);//wlp
    
    printf("lwp %-5.2d.\n", 1234567);//lwp
    printf("lpw %-2.5d.\n", 1234567);//lpw

    printf("\n**********with equal************\n\n");

    printf("w=p l %8.8d.\n", 1234567);//w=p l 
    printf("w=l p %7.2d.\n", 1234567);//w=l p
    printf("w=p=l %7.7d.\n", 1234567);//w=p=l
    printf("w p=l %8.7d.\n", 1234567);//w p=l
    printf("p=l w %2.7d.\n", 1234567);//p=l w
    printf("p w=l %7.8d.\n", 1234567);//p w=l
    printf("l w=p %6.6d.\n", 1234567);//l w=p

	printf("\n**********with equal, with minus************\n\n");
    
	printf("w=p l %-8.8d.\n", 1234567);//w=p l 
    printf("w=l p %-7.2d.\n", 1234567);//w=l p
    printf("w=p=l %-7.7d.\n", 1234567);//w=p=l
    printf("w p=l %-8.7d.\n", 1234567);//w p=l
    printf("p=l w %-2.7d.\n", 1234567);//p=l w
    printf("p w=l %-7.8d.\n", 1234567);//p w=l
    printf("l w=p %-6.6d.\n", 1234567);//l w=p */
/*
	printf("% .2d", 0);
	printf("\n");
	ft_printf("% .2d", 0);
*/

    /* printf("@moulitest:%.d.%.0d.\n", 0, 0);
    ft_printf("@moulitest:%.d.%.0d.\n", 0, 0); 
    printf("@moulitest:%5.d.%5.0d.\n", 0, 0);
    ft_printf("@moulitest:%5.d.%5.0d.", 0, 0);*/

    //ft_printf("%lld", -9223372036854775808);
    //ft_printf("%lu\n", -42);
    //ft_printf("{%*3d}\n", 5, 0);
    //ft_printf("%o\n", -5);
 //   ft_printf("%-8.*o.", 5, 8);
	//printf("%-10.*d.\n", -5, 16);
	//ft_printf("%-10.*d.\n", -5, 16);
	//ft_printf("%#.6o.\n", 16);
	//printf("%#.6o.\n", 16);

	//printf("@moulitest: %#.x %#.0x.\n", 0, 0);
   // ft_printf("@moulitest: %#.x %#.0x.\n", 0, 0);
/*	printf("%.0u.", 0);
	printf("\n");
	ft_printf("%.0u.", 0);
*/
	printf("%5.0u.", 0);
	printf("\n");
	ft_printf("%5.0u.", 0);

    /* ft_printf("pwl .%-10.15d.\n", 1234567);//pwl
	printf("pwl .%-10.15d.\n", 1234567); */



    /* printf("\n**********without equal, with space*********\n\n");
    printf("pwl .% 10.12d.\n", 1234567);//pwl
    printf("plw .% 5.12d.\n", 1234567);//plw

    printf("wpl .% 10.8d.\n", 1234567);//wpl
    printf("wlp .% 10.2d.\n", 1234567);//wlp
    
    printf("lwp .% 5.2d.\n", 1234567);//lwp
    printf("lpw .% 2.5d.\n", 1234567);//lpw

    printf("\n**********without equal, with minus, with space*********\n\n");

    printf("pwl .% -10.12d.\n", 1234567);//pwl
    printf("plw .% -5.12d.\n", 1234567);//plw

    printf("wpl .% -10.8d.\n", 1234567);//wpl
    printf("wlp .% -10.2d.\n", 1234567);//wlp
    
    printf("lwp .% -5.2d.\n", 1234567);//lwp
    printf("lpw .% -2.5d.\n", 1234567);//lpw
    
    printf("\n**********with equal, without minus, with space************\n\n");

    printf("w=p l .% 8.8d.\n", 1234567);//w=p l 
    printf("w=l p .% 7.2d.\n", 1234567);//w=l p
    printf("w=p=l .% 7.7d.\n", 1234567);//w=p=l
    printf("w p=l .% 8.7d.\n", 1234567);//w p=l
    printf("p=l w .% 2.7d.\n", 1234567);//p=l w
    printf("p w=l .% 7.8d.\n", 1234567);//p w=l
    printf("l w=p .% 6.6d.\n\n", 1234567);//l w=p

    printf("\n**********with equal, with minus, with space************\n\n");
    
    printf("w=p l .%- 8.8d.\n", 1234567);//w=p l 
    printf("w=l p .%- 7.2d.\n", 1234567);//w=l p
    printf("w=p=l .%- 7.7d.\n", 1234567);//w=p=l
    printf("w p=l .%- 8.7d.\n", 1234567);//w p=l
    printf("p=l w .%- 2.7d.\n", 1234567);//p=l w
    printf("p w=l .%- 7.8d.\n", 1234567);//p w=l
    printf("l w=p .%- 6.6d.\n", 1234567);//l w=p */
/*
	printf("s = %*.*s.\n", 6, 3, "abcde");
	ft_printf("s = %*.*s.\n", 6, 3, "abcde");
	printf("char = %*%.\n", 5);
	ft_printf("char = %*%.\n", -5);
*/
    /* ft_printf("wpl .%10.8d.\n", 1234567);//
    printf("wpl .%10.8d.\n", 1234567);//
     */
    
    /* TEST MY FT_PRINTF!!!!!!!!!!!!

    ft_printf("**********without equal*********\n");
    ft_printf("%10.12d.\n", 1234567);//pwl
    ft_printf("%5.12d.\n", 1234567);//plw

    ft_printf("%10.8d.\n", 1234567);//wpl
    ft_printf("%10.2d.\n", 1234567);//wlp
    
    ft_printf("%5.2d.\n", 1234567);//lwp
    ft_printf("%2.5d.\n", 1234567);//lpw

    ft_printf("**********without equal, with minus*********\n");

    ft_printf("%-10.12d.\n", 1234567);//pwl
    ft_printf("%-5.12d.\n", 1234567);//plw

    ft_printf("%-10.8d.\n", 1234567);//wpl
    ft_printf("%-10.2d.\n", 1234567);//wlp
    
    ft_printf("%-5.2d.\n", 1234567);//lwp
    ft_printf("%-2.5d.\n", 1234567);//lpw

    printf("**********with equal************\n");

    ft_printf("%8.8d.\n", 1234567);//w=p l 
    ft_printf("%7.2d.\n", 1234567);//w=l p
    ft_printf("%7.7d.\n", 1234567);//w=p=l
    ft_printf("%8.7d.\n", 1234567);//w p=l
    ft_printf("%2.7d.\n", 1234567);//p=l w
    ft_printf("%7.8d.\n", 1234567);//p w=l
    ft_printf("%6.6d.\n", 1234567);//l w=p

	printf("**********with equal, with minus************\n");
    
	ft_printf("%-8.8d.\n", 1234567);//w=p l 
    ft_printf("%-7.2d.\n", 1234567);//w=l p
    ft_printf("%-7.7d.\n", 1234567);//w=p=l
    ft_printf("%-8.7d.\n", 1234567);//w p=l
    ft_printf("%-2.7d.\n", 1234567);//p=l w
    ft_printf("%-7.8d.\n", 1234567);//p w=l
    ft_printf("%-6.6d.\n", 1234567);//l w=p
	 */
    
    






	/*****************Строки****************/

	/*ft_printf("%1.25hs\n", 12);
    ft_printf("%1.25hhs\n", 12);
    ft_printf("%1.25ls\n", 12);
    ft_printf("%1.25lls\n", 12);
    ft_printlf("%1.25Ls\n", 12); 
    printf("%+4c", 'c');
    printf("%-4c",33);
    ft_printf("j%4lcaasd%1cx", 'w','a');
    printf("%d", printf("j%4lcaasd%1cx", 'w','a'));*/

	//printf("%+10s\n", "this");
	//printf("%s\n", "");   
	//printf("% 10s\n", "this");    
	//printf("%010s\n", "this");    
	//printf("%d", printf("%023.3s\n", "1asd"));
	//ft_printf("%-12.6s1\n", "this is sparta");
	
	/****************Smile****************/
	/*ft_printf("%1337q");
	ft_printf("%42q");
	ft_printf("%2q", 1);
	ft_printf("%2q", 2);
	ft_printf("%2q", 3); */

	
    return (0);
}