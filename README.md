# ClosestPair_ConvexHull
closest pair problem, convex hull problem

Point2D.h
	xy평면 상의 점을 나타내는 클래스를 정의.
	좌표의 표현형을 바꿔 이용할 걸 대비해 템플릿으로 구현.

Geometry.h
	Point2D 객체에 대한 기하 연산(거리, theta연산)을 정의하였다.
	
ConvexHull.h, ConvexHull.cpp
	컨벡스헐을 계산하는 클래스. Graham scan을 이용해 구현하였다.
	
ClosestPair.h, ClosestPair.cpp
	최근접 점쌍을 구하는 클래스.
	이 클래스를 이용하는 호출자(여기선 main())의 값들에 영향을 주지 않기 위해
	인자로 전달받은 점집합(vector<Point2D<int> pointList)의 사본을 만들어 이용한다.
	사본 없이 원본을 직접 이용하면 연산 속도를 조금 줄일 수 있다.

PA04_201024441.cpp
	main()이 포함된 본문.
	
/////////////////////////////////////////////////////////////////////////////////
input100.txt를 입력할 때,
가끔 closest pair의 결과가 정확히 나오지 않는 경우가 있습니다.
결과로 리턴 받는 최종 결과물(두 점을 원소로 하는 std::pair)중 두번째 값이 쓰레기값인 경우입니다.
동일한 조건에서 여러번 실험해보았지만 윈도우와 우분투 모두 정상적인 답을 도출하다 가끔 쓰레기값을 도출합니다.
이 부분은 해결하지 못했습니다.
