TEMPLATE = subdirs

SUBDIRS += \
    Common \
    Frontend \
#    Application \
#    Domain \
#    Infrastructure

Common.file = Common/Common.pro

Frontend.file = Frontend/Frontend.pro

Application.file = Backend/Application/Application.pro

Domain.file = Backend/Domain/Domain.pro

Infrastructure.file = Backend/Infrastructure/Infrastructure.pro
