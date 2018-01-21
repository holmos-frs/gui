#include "ComputationThread.h"

ComputationThread::ComputationThread(unsigned int n0, unsigned int n1)
    : m_thread() {
    this->n0 = n0; // Vertical size a.k.a. height
    this->n1 = n1; // Horizontal size a.k.a. width

    camera_image = new cv::Mat(n0, n1, CV_8UC3);
    magnitude_spectrum = new cv::Mat(n0, n1, CV_8UC3);
    phase_angle = new cv::Mat(n0, n1, CV_8UC3);
}

ComputationThread::~ComputationThread() {
    delete camera_image;
    delete magnitude_spectrum;
    delete phase_angle;
}

void ComputationThread::run() {
    m_thread = std::thread(&ComputationThread::do_work, this);
}

void ComputationThread::stop() {
    m_should_stop = true;
    m_thread.join();
}

void ComputationThread::do_work() {
    /* Open WebCam device */
    webcam = new cv::VideoCapture(0);

    if(!webcam->isOpened()) {
	std::cerr << "[ERROR] Could not open webcam" << std::endl;
	return;
    }

    while(!m_should_stop) {
	webcam->retrieve(*camera_image);
	std::cout << "Frame dimensions: " << camera_image->cols << "x"
	    << camera_image->rows << std::endl;
    }
}
