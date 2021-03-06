#include <stdio.h>
#include "Exercise3_1.h"
#include <time.h>

void test_original_binsearch()
{
    int test[] = {1,2,4,6,8,9,12,13,20};
    int x = 7;
    int n = 9;

    int res = binsearch(x, test, n);
    int expected = -1;
    printf("expected:%i\nactual:%i\npass:%i\n", expected, res, expected==res);
}


void test_binsearch_better()
{
    int test[] = {1,2,4,6,8,9,12,13,20};
    int n = 9;
   
    int x = 13;
    int expected = 7;

    int res = binsearch_better(x, test, n);
    
    printf("expected:%i\nactual:%i\npass:%i\n", expected, res, expected==res);
}

void test_comp(){
    int test[] = {4, 6, 7, 9, 10, 12, 13, 14, 14, 14, 32, 37, 39, 41, 41, 46, 49, 50, 52, 52, 52, 53, 54, 56, 56, 57, 60, 62, 64, 65, 65, 67, 69, 69, 70, 71, 72, 77, 78, 80, 80, 82, 85, 85, 86, 86, 88, 88, 90, 92, 97, 98, 101, 101, 102, 103, 105, 106, 106, 112, 112, 114, 115, 116, 122, 127, 130, 130, 131, 131, 132, 136, 138, 140, 140, 141, 142, 144, 144, 145, 146, 147, 147, 149, 149, 156, 162, 165, 167, 167, 168, 169, 169, 174, 174, 174, 176, 177, 178, 181, 182, 182, 183, 184, 189, 189, 190, 199, 202, 204, 204, 209, 210, 211, 214, 217, 219, 220, 222, 228, 229, 229, 230, 232, 235, 236, 237, 240, 242, 246, 249, 252, 252, 253, 256, 256, 260, 260, 262, 268, 272, 273, 275, 275, 281, 283, 284, 285, 285, 286, 287, 288, 289, 290, 291, 294, 296, 296, 300, 304, 306, 309, 311, 311, 314, 316, 317, 318, 319, 323, 325, 327, 332, 333, 337, 341, 342, 342, 346, 347, 348, 352, 352, 354, 356, 357, 358, 361, 365, 368, 369, 373, 373, 373, 376, 377, 382, 384, 385, 387, 388, 389, 392, 392, 396, 397, 398, 402, 406, 406, 412, 414, 417, 418, 419, 419, 421, 424, 424, 424, 429, 429, 432, 435, 435, 436, 439, 440, 445, 449, 451, 452, 455, 456, 457, 460, 461, 461, 465, 467, 467, 468, 470, 470, 470, 471, 474, 475, 476, 477, 477, 477, 480, 482, 483, 486, 487, 490, 491, 491, 492, 493, 495, 496, 500, 500, 501, 509, 520, 524, 525, 528, 528, 529, 530, 535, 540, 542, 545, 546, 548, 549, 552, 553, 557, 558, 562, 566, 568, 570, 574, 576, 578, 581, 582, 582, 582, 582, 584, 585, 586, 586, 588, 590, 590, 591, 598, 602, 605, 607, 607, 609, 613, 613, 617, 618, 629, 629, 630, 630, 632, 634, 634, 635, 638, 643, 646, 648, 655, 660, 664, 667, 667, 667, 668, 668, 670, 670, 671, 674, 678, 679, 684, 685, 686, 688, 689, 694, 696, 700, 702, 703, 708, 710, 715, 716, 718, 721, 723, 724, 725, 726, 727, 727, 731, 732, 732, 732, 734, 735, 738, 739, 739, 741, 741, 742, 746, 749, 760, 766, 766, 766, 766, 768, 768, 768, 772, 775, 782, 783, 786, 789, 796, 798, 799, 799, 801, 801, 802, 802, 803, 807, 808, 808, 810, 814, 827, 829, 829, 829, 830, 830, 832, 832, 834, 834, 838, 842, 842, 842, 843, 843, 846, 847, 848, 852, 855, 855, 856, 859, 860, 861, 864, 864, 866, 867, 868, 872, 874, 879, 883, 886, 890, 890, 892, 892, 897, 899, 900, 902, 906, 906, 907, 908, 913, 914, 923, 926, 928, 929, 930, 930, 931, 932, 933, 933, 935, 938, 941, 942, 944, 946, 946, 947, 950, 952, 956, 959, 962, 966, 967, 967, 969, 971, 974, 974, 974, 978, 980, 982, 986, 986, 986, 988, 989, 991, 991, 993, 994, 995};
    int n = 500;

    int x = 273;
    int expected = 141;

    int res;
    res = binsearch(x, test, n);
    printf("expected:%i\nactual:%i\npass:%i\n", expected, res, expected==res);   

    res = binsearch_better(x, test, n);
    printf("expected:%i\nactual:%i\npass:%i\n", expected, res, expected==res);   


    time_t start, end;
    int trials = 10000000;
    start = clock();
    for (int i = 0; i<trials; i++)
    {
        res = binsearch_v3(x, test, n);
    }
    end = clock();
    float span_orig = (float)(end-start)/CLOCKS_PER_SEC;

    start = clock();
    for (int i = 0; i<trials; i++)
    {
   //     res = binsearch_v3(x, test, n);
        res = binsearch_v4(x, test, n);
    }
    end = clock();
    float span_new = (float)(end-start)/CLOCKS_PER_SEC;


    printf("orig:%f\n new:%f\n", span_orig, span_new);


}

int main(){
    //test_original_binsearch();
    //test_binsearch_better();
    test_comp();    



}