
#include <QPointF>

class QGTPoint3D
{
public:
	QGTPoint3D();
	QGTPoint3D(qreal xpos, qreal ypos, qreal zpos);
	
	inline qreal x() const;
	inline qreal y() const;
	inline qreal z() const;

	inline void setX(qreal x);
	inline void setY(qreal y);
	inline void setZ(qreal z);

private:
	qreal xp;
	qreal yp;
	qreal zp;
};

inline QGTPoint3D::QGTPoint3D() : xp(0), yp(0), zp(0) { }
inline QGTPoint3D::QGTPoint3D(qreal xpos, qreal ypos, qreal zpos) : xp(xpos), yp(ypos), zp(zpos) { }

inline qreal QGTPoint3D::x() const
{
	return xp;
}

inline qreal QGTPoint3D::y() const
{
	return yp;
}

inline qreal QGTPoint3D::z() const
{
	return zp;
}

inline void QGTPoint3D::setX(qreal x)
{
	xp = x;
}

inline void QGTPoint3D::setY(qreal y)
{
	yp = y;
}

inline void QGTPoint3D::setZ(qreal z)
{
	zp = z;
}
