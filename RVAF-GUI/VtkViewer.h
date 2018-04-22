#pragma once
#include "afxwin.h"

#include "vtkMydProp.h"

#include <vtkResliceCursor.h>  
#include <vtkResliceCursorWidget.h>  

#include <vtkPlane.h>  
#include <vtkPlaneSource.h>  
#include <vtkPlaneWidget.h>  

#include <vtkImagePlaneWidget.h>  
#include <vtkResliceCursorThickLineRepresentation.h>  
#include <vtkResliceCursor.h>  

#include <vtkCommand.h>  
#include <vtkViewport.h>  
#include <vtkViewDependentErrorMetric.h>  

#include <vtkSmartPointer.h>  

#include <vtkRenderer.h>  
#include <vtkRendererSource.h>  
#include <vtkRenderingOpenGLModule.h>  
#include <vtkRenderWindow.h>  
#include <vtkWin32OpenGLRenderWindow.h>  
#include <vtkWin32RenderWindowInteractor.h> 

#include <vtkPolyVertex.h>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>

#include <vtkLookupTable.h>
#include <vtkFloatArray.h>
#include <vtkPointData.h>

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)

using Pointf = struct _Pointf{
	float x;
	float y;
	float z;
	float r;
	float g;
	float b;
};

class CVtkViewer : public CStatic
{
	DECLARE_DYNAMIC(CVtkViewer)

public:
	CVtkViewer();
	virtual ~CVtkViewer();

	vtkSmartPointer<vtkActor> actor;
	void ReadPointCloud(std::vector<Pointf>&);
	void ReadEularAngle(float a, float b, float c);

public:
	//3.2 ����CvtkView��PreSubclassWindow����������OnPaint()����  
	//PreSubclassWindow�������𴴽�VTK���ӻ����ߣ�OnPaint()��������ͻ����ڳ�����Ⱦ��  
	//vtkAcor,vtkRenderer,vtkRenderWindow,vtkRenderWindowInteractor�ĸ����֡���Ȼ������Ҫ����������vtkRenderWindowInteractorStyle,�Լ����գ����ʣ���ɫ�ȡ�  
	//��CvtkView��ͷ�ļ��ж�����ض��󣬲���PreSubclassWindow������ʵ�����͹������ӻ�����  
	void PreSubclassWindow();
	void SetImageData(vtkSmartPointer<vtkImageData> ImageData);
	void SetupReslice();
	void MoveWindow(CRect);

private:
	vtkSmartPointer< vtkImagePlaneWidget >   m_ImagePlaneWidget;
	vtkSmartPointer< vtkResliceCursorWidget> m_ResliceCursorWidget;
	vtkSmartPointer< vtkResliceCursor >      m_ResliceCursor;
	vtkSmartPointer< vtkResliceCursorThickLineRepresentation > m_ResliceCursorRep;

	vtkSmartPointer<vtkRenderer>         m_Renderer;
	vtkSmartPointer<vtkRenderWindow> m_RenderWindow;
	vtkSmartPointer<vtkImageData>       m_ImageData;

	

	//m_DirectionΪ�����־��ȡֵ�ֱ�Ϊ0,1��2���ֱ����X�ᣬY���Z�᷽��  
	int m_Direction;

protected:
	DECLARE_MESSAGE_MAP()
};

//���û��ı�ͼ���зֵ�������ʱ����ת���������ƽ������ϵ����ͼ���з�ƽ��������Ӧ�ĸı䣬  
//������µ��з�ƽ����µ���ά��ͼ��vtkImagePlaneWidget�����У�����ʵ����ά��ͼ��ͬ�����²�����  
///����������ƣ�ʵ��һ��vtkCommand���࣬������vtkResliceCursorWidget::ResliceAxesChangedEvent��Ϣ����ʵ����Ӧ�ĸ��²�����  
//class vtkResliceCursorCallback : public vtkCommand
//{
//public:
//	static vtkResliceCursorCallback *New()
//	{
//		return new vtkResliceCursorCallback;
//	}
//
//	CVtkViewer* view[4];
//
//public:
//	void Execute(vtkObject *caller, unsigned long /*ev*/,
//		void *callData)
//	{
//		vtkResliceCursorWidget *rcw = dynamic_cast<vtkResliceCursorWidget *>(caller);
//		if (rcw)
//		{
//			for (int i = 0; i < 3; i++)
//			{
//				vtkPlaneSource *ps =
//					static_cast<vtkPlaneSource *>(view[i]->GetImagePlaneWidget()->GetPolyDataAlgorithm());
//
//				ps->SetOrigin(view[i]->GetResliceCursorWidget()->
//					GetResliceCursorRepresentation()->GetPlaneSource()->GetOrigin());
//				ps->SetPoint1(view[i]->GetResliceCursorWidget()->
//					GetResliceCursorRepresentation()->GetPlaneSource()->GetPoint1());
//				ps->SetPoint2(view[i]->GetResliceCursorWidget()->
//					GetResliceCursorRepresentation()->GetPlaneSource()->GetPoint2());
//
//				view[i]->GetImagePlaneWidget()->UpdatePlacement();
//				view[i]->Render();
//			}
//			view[3]->Render();
//		}
//
//	}
//
//	vtkResliceCursorCallback() {}
//};