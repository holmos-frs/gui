#include <iostream>
#include <thread>
#include <mutex>
#include <opencv2/opencv.hpp>
#include <fftw3.h>

class ComputationThread {
    public:
	ComputationThread(unsigned int n0, unsigned int n1);
	virtual ~ComputationThread();
	cv::Mat *get_camera_image();
	cv::Mat *get_magnitude_spectrum();
	cv::Mat *get_phase_angle();

	void run();
	void stop();

    private:
	void do_work();
	bool m_should_stop = false;
	unsigned int n0, n1;
	cv::Mat *camera_image, *magnitude_spectrum, *phase_angle;
	cv::VideoCapture *webcam;
	std::thread m_thread;
};
