#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int erosion_size =  2;
int erosion_times = 2;
int thresh = 10;
	
int main(int argc, char **argv)
{	
	if (argc != 4 )
	{
		cout << "error , you have to specify correct argument \n";
		return 1 ;
	}
	char* input_file = argv[1];
	char* output_bigparticle_file = argv[2];
	char* output_smallparticle_file = argv[3];
	
	Mat input_img = imread(input_file);
	Mat big_particles_img;
	
    Mat erosion_element = getStructuringElement(MORPH_ELLIPSE,
                                               Size(2*(erosion_size)+1 , 2*(erosion_size)+1),
                                               Point(erosion_size, erosion_size));
    erode(input_img, big_particles_img, erosion_element, Point(-1, -1), erosion_times);
	imwrite(output_bigparticle_file, big_particles_img);
	
	Mat mask_img;
	dilate( big_particles_img, mask_img, erosion_element, Point(-1, -1), erosion_times);
	threshold(mask_img, mask_img, thresh, 255, THRESH_BINARY);
	bitwise_not(mask_img, mask_img);
	imwrite("mask.jpg",mask_img);
	
	Mat small_particles_img;
	min(input_img, mask_img, small_particles_img);
	imwrite(output_smallparticle_file, small_particles_img);
	
    return 0;
}
