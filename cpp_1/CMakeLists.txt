cmake_minimum_required(VERSION 2.8.3)
project(cpp_1)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)



catkin_package(

)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)




add_executable(paixu src/paixu.c)
target_link_libraries(paixu ${catkin_LIBRARIES})

add_executable(paixu-2 src/paixu-2.c)
target_link_libraries(paixu-2 ${catkin_LIBRARIES})
add_executable(oulajiaoyusiyuanshuzhijianzhuanhua src/oulajiaoyusiyuanshuzhijianzhuanhua.cpp)
target_link_libraries(oulajiaoyusiyuanshuzhijianzhuanhua ${catkin_LIBRARIES})

add_executable(oulajiaoyusiyuanshuzhijianzhuanhua-1 src/oulajiaoyusiyuanshuzhijianzhuanhua-1.cpp)
target_link_libraries(oulajiaoyusiyuanshuzhijianzhuanhua-1 ${catkin_LIBRARIES})

add_executable(oulajiaoyusiyuanshuzhijianzhuanhua-2 src/oulajiaoyusiyuanshuzhijianzhuanhua-2.cpp)
target_link_libraries(oulajiaoyusiyuanshuzhijianzhuanhua-2 ${catkin_LIBRARIES})

add_executable(oulajiaoyusiyuanshuzhijianzhuanhua-3 src/oulajiaoyusiyuanshuzhijianzhuanhua-3.cpp)
target_link_libraries(oulajiaoyusiyuanshuzhijianzhuanhua-3 ${catkin_LIBRARIES})

add_executable(qiuzhixin src/qiuzhixin.cpp)
target_link_libraries(qiuzhixin ${catkin_LIBRARIES})
add_executable(juzhensuanfa src/juzhensuanfa.cpp)
target_link_libraries(juzhensuanfa ${catkin_LIBRARIES})

add_executable(xiefangchejuzhen src/xiefangchejuzhen.cpp)
target_link_libraries(xiefangchejuzhen ${catkin_LIBRARIES})

add_executable(zuobiaobianhuan src/zuobiaobianhuan.cpp)
target_link_libraries(zuobiaobianhuan ${catkin_LIBRARIES})

add_executable(butongchidu src/butongchidu.cpp)
target_link_libraries(butongchidu ${catkin_LIBRARIES})

add_executable(nijuzhenqiujie src/nijuzhenqiujie.cpp)
target_link_libraries(nijuzhenqiujie ${catkin_LIBRARIES})

add_executable(ABBzhunhuanjuzhen src/ABBzhunhuanjuzhen.cpp)
target_link_libraries(ABBzhunhuanjuzhen ${catkin_LIBRARIES})

add_executable(ABBzhunhuanjuzhen-2 src/ABBzhunhuanjuzhen-2.cpp)
target_link_libraries(ABBzhunhuanjuzhen-2 ${catkin_LIBRARIES})

add_executable(chazhiyunsuanx-y src/chazhiyunsuanx-y.cpp)
target_link_libraries(chazhiyunsuanx-y ${catkin_LIBRARIES})

add_executable(xierushuju src/xierushuju.cpp)
target_link_libraries(xierushuju ${catkin_LIBRARIES})

