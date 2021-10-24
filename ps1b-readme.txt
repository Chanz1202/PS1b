/**********************************************************************
 *  Linear Feedback Shift Register (part B) ps1b-readme.txt template
 **********************************************************************/

Name: Hanuman Sai Chanukya Srinivas

Hours to complete assignment: 9
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

In this assignment, I need to encrypt and decrypt same image. we have to take the image by using SFML code and we can encrypt it by using
FibLFSR code. Once the image got encrypted, then if we take encrypted image as input, we have to get original image as output. I accomplished the given task in this assignment.

/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/

I have done converting from alphanumeric password to the LFSR initial seed. But the seed should be minimum 12 bits long. If we put a seed
which is length of 16 bits then it is clearly visible in encrypted format.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

As some part of code is already given by the instructor, it is somewhat easy to add the remaining code to get the desired output. I also read some topics from the web.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

When i run my code I got segmentation fault, then i realised that image is in big size. After I change my image which is in less size, then the code worked.
If we give any less number of seed bits in command line then the image will display itself. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

I used the following bits to check whether the alphanumeric password will work or not, i.e., a1b2c3d4e5f6g7h8

