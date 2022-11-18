HEADERS += \
    $$PWD/Controller/SignalController.h \
    $$PWD/Controller/channelcontroller.h \
    $$PWD/Controller/collectionparacontroller.h \
    $$PWD/Controller/dictionarycontroller.h \
    $$PWD/Controller/projectcontroller.h \
    $$PWD/Controller/usercontroller.h \
    $$PWD/Dao/channeldao.h \
    $$PWD/Dao/collectionparasdao.h \
    $$PWD/Dao/dictionarydao.h \
    $$PWD/Dao/pdsql.h \
    $$PWD/Dao/pdsqlinitialize.h \
    $$PWD/Dao/postdao.h \
    $$PWD/Dao/projectdao.h \
    $$PWD/Dao/singlesignaldao.h \
    $$PWD/Dao/sumsignaldao.h \
    $$PWD/Dao/userdao.h \
    $$PWD/Domain/channel.h \
    $$PWD/Domain/collectionparas.h \
    $$PWD/Domain/dictionary.h \
    $$PWD/Domain/post.h \
    $$PWD/Domain/project.h \
    $$PWD/Domain/singlesignal.h \
    $$PWD/Domain/sumSignal.h \
    $$PWD/Domain/user.h \
    $$PWD/Logger/log.h \
    $$PWD/RedisTools/qtredis.h \
    $$PWD/RedisTools/rapidjson/allocators.h \
    $$PWD/RedisTools/rapidjson/cursorstreamwrapper.h \
    $$PWD/RedisTools/rapidjson/document.h \
    $$PWD/RedisTools/rapidjson/encodedstream.h \
    $$PWD/RedisTools/rapidjson/encodings.h \
    $$PWD/RedisTools/rapidjson/error/en.h \
    $$PWD/RedisTools/rapidjson/error/error.h \
    $$PWD/RedisTools/rapidjson/filereadstream.h \
    $$PWD/RedisTools/rapidjson/filewritestream.h \
    $$PWD/RedisTools/rapidjson/fwd.h \
    $$PWD/RedisTools/rapidjson/internal/biginteger.h \
    $$PWD/RedisTools/rapidjson/internal/diyfp.h \
    $$PWD/RedisTools/rapidjson/internal/dtoa.h \
    $$PWD/RedisTools/rapidjson/internal/ieee754.h \
    $$PWD/RedisTools/rapidjson/internal/itoa.h \
    $$PWD/RedisTools/rapidjson/internal/meta.h \
    $$PWD/RedisTools/rapidjson/internal/pow10.h \
    $$PWD/RedisTools/rapidjson/internal/regex.h \
    $$PWD/RedisTools/rapidjson/internal/stack.h \
    $$PWD/RedisTools/rapidjson/internal/strfunc.h \
    $$PWD/RedisTools/rapidjson/internal/strtod.h \
    $$PWD/RedisTools/rapidjson/internal/swap.h \
    $$PWD/RedisTools/rapidjson/istreamwrapper.h \
    $$PWD/RedisTools/rapidjson/memorybuffer.h \
    $$PWD/RedisTools/rapidjson/memorystream.h \
    $$PWD/RedisTools/rapidjson/msinttypes/inttypes.h \
    $$PWD/RedisTools/rapidjson/msinttypes/stdint.h \
    $$PWD/RedisTools/rapidjson/ostreamwrapper.h \
    $$PWD/RedisTools/rapidjson/pointer.h \
    $$PWD/RedisTools/rapidjson/prettywriter.h \
    $$PWD/RedisTools/rapidjson/rapidjson.h \
    $$PWD/RedisTools/rapidjson/reader.h \
    $$PWD/RedisTools/rapidjson/schema.h \
    $$PWD/RedisTools/rapidjson/stream.h \
    $$PWD/RedisTools/rapidjson/stringbuffer.h \
    $$PWD/RedisTools/rapidjson/writer.h \
    $$PWD/RedisTools/reader.h \
    $$PWD/RedisTools/rediscontroller.h \
    $$PWD/Result/result.h \
    $$PWD/Service/channelservice.h \
    $$PWD/Service/collectionparaservice.h \
    $$PWD/Service/dictionaryservice.h \
    $$PWD/Service/projectservice.h \
    $$PWD/Service/singlesignalservice.h \
    $$PWD/Service/sumsignalservice.h \
    $$PWD/Service/userservice.h \
    $$PWD/Signal/BaseEchoSignal.h \
    $$PWD/Signal/StaticSpectralEchoSignal.h \
    $$PWD/Tools/tool.h \
    $$PWD/Utils/DataModal.h \
    $$PWD/Utils/DataStructure.h \
    $$PWD/Utils/FFTWUtil.h \
    $$PWD/Utils/GetDataThread.h \
    $$PWD/Utils/JSaveCollectionDataThread.h \
    $$PWD/Utils/PlayBackThread.h \
    $$PWD/Utils/SaveCollectionDataThread.h \
    $$PWD/Utils/SignalFeature.h \
    $$PWD/Utils/SmartFFTWComplexArray.h \
    $$PWD/Utils/ThreadSafeQueue.h \
    $$PWD/Utils/UUIDUtil.h \
    $$PWD/Utils/aircraftcasingvibratesystem.h \
    $$PWD/Utils/fftw3.h \
    $$PWD/View/JSpectrumWindow.h \
    $$PWD/View/NewProjectDialog.h \
    $$PWD/View/OpenDataFileDialog.h \
    $$PWD/View/alalysisresultview.h \
    $$PWD/View/jbasesamplewindow.h \
    $$PWD/View/jdataviewecho.h \
    $$PWD/View/jdynamicwidget.h \
    $$PWD/View/jsampleview.h \
    $$PWD/View/jvoiceranddata.h \
    $$PWD/View/jvoicesampleview.h \
    $$PWD/View/qcustomplot.h \
    $$PWD/View/redissetupdialog.h \
    $$PWD/View/spectrum.h \
    $$PWD/tDemo/singnalcontrollertest.h



SOURCES += \
    $$PWD/Controller/SignalController.cpp \
    $$PWD/Controller/channelcontroller.cpp \
    $$PWD/Controller/collectionparacontroller.cpp \
    $$PWD/Controller/dictionarycontroller.cpp \
    $$PWD/Controller/projectcontroller.cpp \
    $$PWD/Controller/usercontroller.cpp \
    $$PWD/Dao/channeldao.cpp \
    $$PWD/Dao/collectionparasdao.cpp \
    $$PWD/Dao/dictionarydao.cpp \
    $$PWD/Dao/pdsql.cpp \
    $$PWD/Dao/pdsqlinitialize.cpp \
    $$PWD/Dao/postdao.cpp \
    $$PWD/Dao/projectdao.cpp \
    $$PWD/Dao/singlesignaldao.cpp \
    $$PWD/Dao/sumsignaldao.cpp \
    $$PWD/Dao/userdao.cpp \
    $$PWD/Domain/channel.cpp \
    $$PWD/Domain/collectionparas.cpp \
    $$PWD/Domain/dictionary.cpp \
    $$PWD/Domain/post.cpp \
    $$PWD/Domain/project.cpp \
    $$PWD/Domain/singlesignal.cpp \
    $$PWD/Domain/sumSignal.cpp \
    $$PWD/Domain/user.cpp \
    $$PWD/Logger/log.cpp \
    $$PWD/RedisTools/qtredis.cpp \
    $$PWD/RedisTools/reader.cpp \
    $$PWD/RedisTools/rediscontroller.cpp \
    $$PWD/Result/result.cpp \
    $$PWD/Service/channelservice.cpp \
    $$PWD/Service/collectionparaservice.cpp \
    $$PWD/Service/dictionaryservice.cpp \
    $$PWD/Service/projectservice.cpp \
    $$PWD/Service/singlesignalservice.cpp \
    $$PWD/Service/sumsignalservice.cpp \
    $$PWD/Service/userservice.cpp \
    $$PWD/Signal/BaseEchoSignal.cpp \
    $$PWD/Signal/StaticSpectralEchoSignal.cpp \
    $$PWD/Tools/datautil.cpp \
    $$PWD/Tools/tool.cpp \
    $$PWD/Utils/DataModal.cpp \
    $$PWD/Utils/FFTWUtil.cpp \
    $$PWD/Utils/GetDataThread.cpp \
    $$PWD/Utils/JSaveCollectionDataThread.cpp \
    $$PWD/Utils/PlayBackThread.cpp \
    $$PWD/Utils/SaveCollectionDataThread.cpp \
    $$PWD/Utils/SignalFeature.cpp \
    $$PWD/Utils/SmartFFTWComplexArray.cpp \
    $$PWD/Utils/UUIDUtil.cpp \
    $$PWD/Utils/aircraftcasingvibratesystem.cpp \
#    $$PWD/Utils/uuidutil.cpp \
    $$PWD/Utils/getanalysisresultthread.cpp \
    $$PWD/Utils/playbacksinglethread.cpp \
    $$PWD/Utils/redisuploadthread.cpp \
    $$PWD/View/JspectrumWindow.cpp \
    $$PWD/View/NewProjectDialog.cpp \
    $$PWD/View/OpenDataFileDialog.cpp \
    $$PWD/View/alalysisresultview.cpp \
    $$PWD/View/jbasesamplewindow.cpp \
    $$PWD/View/jdataviewecho.cpp \
    $$PWD/View/jdynamicwidget.cpp \
    $$PWD/View/jsampleview.cpp \
    $$PWD/View/jvoiceranddata.cpp \
    $$PWD/View/jvoicesampleview.cpp \
    $$PWD/View/qcustomplot.cpp \
    $$PWD/View/redissetupdialog.cpp \
    $$PWD/View/spectrum.cpp \
    $$PWD/tDemo/channelcontrollertest.cpp \
    $$PWD/tDemo/collectionparacontrollertest.cpp \
    $$PWD/tDemo/dictionarycontrollertest.cpp \
    $$PWD/tDemo/projectcontrollertest.cpp \
    $$PWD/Vo/analysisresult.cpp \
    $$PWD/interface/isignaljumpable.cpp \
    $$PWD/interface/itimeaxis.cpp \
    $$PWD/tDemo/singnalcontrollertest.cpp \
    $$PWD/Vo/sumsignalandprojectnamevo.cpp




DISTFILES +=

FORMS += \
    $$PWD/View/NewProjectDialog.ui \
    $$PWD/View/OpenDataFileDialog.ui \
    $$PWD/View/alalysisresultview.ui \
    $$PWD/View/jdynamicwidget.ui \
    $$PWD/View/redissetupdialog.ui \
    $$PWD/View/spectrum.ui \

