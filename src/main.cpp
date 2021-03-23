#include "types.h"
Mat VJ_Face_Detector(Mat Image, CascadeClassifier fcascade,
    CascadeClassifier ecascade)
{////Takes an image and detects and points out faces and eyes on that image with  the provided Haar cascades
 
    std::vector<Rect> fac;                                                  //variable initialization
    Mat gscale;
    
    cvtColor(Image, gscale, COLOR_BGR2GRAY);                                  // converting to gray-scale
    equalizeHist(gscale, gscale);                                             // equalizing Histogram

  
   fcascade.detectMultiScale(gscale, fac);                                // detecta face in the image

    
    for (int p = 0; p < fac.size(); p++)                                   //for every face
    {

       
        Point center(fac[p].x + fac[p].width / 2, fac[p].y +              //  the center of face
            fac[p].height / 2);
        
       
        ellipse(Image, center, Size(fac[p].width / 2, fac[p].height / 2),   //drawing an ellipse around the face
            0, 0, 360, Scalar(255, 0, 255), 4);
        
       
        Mat face = gscale(fac[p]);                                       //detect eyes on face
        std::vector<Rect> eyes;
        ecascade.detectMultiScale(face, eyes);

        
        for (int q = 0; q < eyes.size(); q++)                            //for every eye
        {

           
            Point eye_center(fac[p].x + eyes[q].x + eyes[q].width / 2,      //build circles around the eye
                fac[p].y + eyes[q].y + eyes[q].height / 2);
            int radius = cvRound((eyes[q].width + eyes[q].height) * 0.25);
            circle(Image, eye_center, radius, Scalar(255, 0, 0), 4);
        }
    }

    
    return Image;                                                            //return the final image
}

int main()
{

    CascadeClassifier fcascade;
    CascadeClassifier ecascade;

    VideoCapture web_cam;
    if (!web_cam.open(0))
    {
        printf("Cannot find a web_cam\n");
        return 1;
    };

    String face_xml_path = samples::findFile(
        "haarcascades/haarcascade_frontalface_alt.xml");
    String eyes_xml_path = samples::findFile(
        "haarcascades/haarcascade_eye_tree_eyeglasses.xml");

    if (!fcascade.load(face_xml_path))
    {
        cout << "Cannot load haarcascades/haarcascade_frontalface_alt.xml\n";
        return 2;
    };
    if (!ecascade.load(eyes_xml_path))
    {
        cout << "Cannot load haarcascade_eye_tree_eyeglasses.xml\n";
        return 3;
    };
   
    Mat Image;
    time_t beginning_time, ending_time;
    while (1)
    {

      
        time(&beginning_time);                           //starting time
        for (int p = 0; p < 60; p++)
        {
            web_cam >> Image;

           
            Image = VJ_Face_Detector(Image, fcascade, ecascade);        // detecting  eyes and face
            imshow("web_cam", Image);
            int key = waitKey(5);
            if (key == 27 || key == 'q')
                break;
        }

        
        time(&ending_time);                                                  //ending time
        cout << "Frames Per Second = " << 60 / difftime(ending_time, beginning_time) << endl;
    }
    web_cam.release();
    return 0;
}

