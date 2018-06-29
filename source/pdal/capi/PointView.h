/*
 * Copyright (c) Simverge Software LLC - All Rights Reserved
 */
#ifndef PDAL_CAPI_POINTVIEW_H
#define PDAL_CAPI_POINTVIEW_H

#include "Forward.h"

#ifdef __cplusplus /* __cplusplus */

namespace pdal
{
	namespace capi
	{
		extern "C"
		{
#else
#include <stdbool.h> // for bool
#include <stdint.h> // for uint64_t
#endif
			/**
			 * Disposes the provided point `view`.
			 * 
			 * @param view The point view to dispose
			 */
			PDAL_C_API void PDALDisposePointView(PDALPointViewPtr view);

			/**
			 * Returns the ID of the provided point `view`.
			 * 
			 * @see pdal::PointView::id
			 * 
			 * @param view The point view
			 * @return The view's ID
			 */
			PDAL_C_API int PDALGetPointViewId(PDALPointViewPtr view);

			/**
			 * Returns the number of points in the provided `view`.
			 * 
			 * @see pdal::PointView::size
			 * 
			 * @param view The point view
			 * @return The number of points
			 */
			PDAL_C_API uint64_t PDALGetPointViewSize(PDALPointViewPtr view);

			/**
			 * Returns whether the provided point `view` is empty, i.e., has no points.
			 * 
			 * @see pdal::PointView::empty
			 * 
			 * @param view The point view
			 * @return Whether the point view is empty
			 */
			PDAL_C_API bool PDALIsPointViewEmpty(PDALPointViewPtr view);

			/**
			 * Clones the provided point `view`.
			 * 
			 * @see pdal::PointView::makeNew
			 * 
			 * @param view The original point view
			 * @return A pointer to the new point view
			 */
			PDAL_C_API PDALPointViewPtr PDALClonePointView(PDALPointViewPtr view);

			/**
			 * Returns the proj4 projection string for the provided point `view`.
			 *
			 * @see pdal::PointView::spatialReference
			 * 
			 * @param view The point view
			 * @param[out] proj The buffer used to hold the resulting proj4 projection string
			 * @param size The size of the proj4 projection string buffer
			 * @return The size of the resulting proj4 projection string
			 */
			PDAL_C_API size_t PDALGetPointViewProj4(PDALPointViewPtr view, char *proj, size_t size);

			/**
			 * Returns the Well-Known Text (WKT) projection string for the provided point `view`.
			 * @see pdal::PointView::spatialReference
			 * 
			 * @param view The point view
			 * @param[out] wkt The buffer used to hold the resulting WKT projection string
			 * @param size The size of the wkt projection string buffer
			 * @param pretty Whether to enhance the formatting of the resulting WKT string
			 * @return The size of the resulting WKT projection string
			 */
			PDAL_C_API size_t PDALGetPointViewWkt(PDALPointViewPtr view, char *wkt, size_t size, bool pretty);

			/**
			 * Returns the point layout for the provided point `view`.
			 *
			 * @note This point view retains ownership of the
			 * layout pointed by the return value. Do not free the returned pointer.
			 * 
			 * @param view The point view
			 * @return The point layout
			 */
			PDAL_C_API PDALPointLayoutPtr PDALGetPointViewLayout(PDALPointViewPtr view);

			/**
			 * Retrieves data for a point based on the provided dimension list.
			 *
			 * @see pdal::PointView::getPackedPoint
			 *
			 * @param view The view that contains the point
			 * @param dims List of dimensions to retrieve
			 * @param idx Index of point to get
			 * @param[out] buf Pointer to buffer to fill
			 * @return The size of the point stored in `buf`
			 */
			PDAL_C_API size_t PDALGetPackedPoint(PDALPointViewPtr view, PDALDimTypeListPtr dims, PDALPointId idx, char *buf);

			/**
			 * Retrieves data for all points based on the provided dimension list.
			 *
			 * @see pdal::PointView::getPackedPoint
			 *
			 * @param view The view that contains the points
			 * @param dims List of dimensions to retrieve
			 * @param idx Index of point to get
			 * @param[out] buf Pointer to buffer to fill
			 * @return The size of the points stored in `buf`
			 */
			PDAL_C_API uint64_t PDALGetAllPackedPoints(PDALPointViewPtr view, PDALDimTypeListPtr dims, char *buf);

			/**
			 * Fill a buffer with point data specified by the dimension list, accounts index
			 * Using this functions it is possible to pack all points into one buffer
			* @param pv    PointView pointer.
			* @param dims  List of dimensions/types to retrieve.
			* @param idx   Index of point to get.
			* @param buf   Pointer to buffer to fill
			*/
			//! PDAL_C_API void appendPackedPoint(PointViewPtr pv, const DimTypeList& dims, PointId idx, std::size_t pointSize, char *buf)

#ifdef __cplusplus
		}
	}
}
#endif /* __cplusplus */

#endif