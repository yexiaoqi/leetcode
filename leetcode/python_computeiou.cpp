#encoding utf - 8
import numpy as np
def compute_iou(box1, box2, wh = False) :
	"""
	compute the iou of two boxes.
	Args :
	box1, box2 : [xmin, ymin, xmax, ymax](wh = False) or [xcenter, ycenter, w, h](wh = True)
	wh : the format of coordinate.
	Return :
	iou : iou of box1 and box2.
	"""
	if wh == False :
		xmin1, ymin1, xmax1, ymax1 = box1
		xmin2, ymin2, xmax2, ymax2 = box2
	else :
		xmin1, ymin1 = int(box1[0] - box1[2] / 2.0), int(box1[1] - box1[3] / 2.0)
		xmax1, ymax1 = int(box1[0] + box1[2] / 2.0), int(box1[1] + box1[3] / 2.0)
		xmin2, ymin2 = int(box2[0] - box2[2] / 2.0), int(box2[1] - box2[3] / 2.0)
		xmax2, ymax2 = int(box2[0] + box2[2] / 2.0), int(box2[1] + box2[3] / 2.0)

## 获取矩形框交集对应的左上角和右下角的坐标（intersection）
		xx1 = np.max([xmin1, xmin2])
		yy1 = np.max([ymin1, ymin2])
		xx2 = np.min([xmax1, xmax2])
		yy2 = np.min([ymax1, ymax2])

		if xx1>xx2 or yy1>yy2:   #两个框不相交
			return 0
## 计算两个矩形框面积
			area1 = (xmax1 - xmin1) * (ymax1 - ymin1)
			area2 = (xmax2 - xmin2) * (ymax2 - ymin2)

			inter_area = (xx2 - xx1)*(yy2 - yy1)
			#inter_area = (np.max([0, xx2 - xx1])) * (np.max([0, yy2 - yy1]))　#计算交集面积
			print(inter_area)
			iou = inter_area / (area1 + area2 - inter_area)

			return iou


if __name__ == '__main__':
	box1 = (100, 10, 200, 20)
	box2 = (180, 5, 300, 15)
	iou = compute_iou(box1, box2)
	print(iou)