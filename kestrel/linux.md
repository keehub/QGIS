# 安装开源中文字体（覆盖宋体、黑体等常用类型）
sudo dnf install -y google-noto-sans-cjk-ttc-fonts wqy-microhei-fonts wqy-zenhei-fonts

# 安装Fedora中文语言支持包
sudo dnf install -y langpacks-zh\_CN

# 验证是否生成成功
locale -a | grep zh\_CN.utf8  # 若输出包含zh\_CN.utf8则成功

# 永久生效（修改系统配置文件）
sudo tee /etc/locale.conf << 'EOF'
LANG="zh\_CN.UTF-8"
LC\_ALL="zh\_CN.UTF-8"
EOF

# 安装PROJ（可选：不安装可选网格以节省空间）
dnf5 install -y --setopt=install\_weak\_deps=False proj-devel

# 安装所有QT6构建依赖
dnf install qt6-qtbase-private-devel qt6-qtlocation-devel qt6-qtmultimedia-devel qt6-qttools-static qca-qt6-devel qca-qt6-ossl qt6-qt3d-devel qt6-qtwebengine-devel python3-pyqt6-devel python3-qscintilla-qt6-devel qscintilla-qt6-devel python3-qscintilla-qt6 clang flex bison geos-devel gdal gdal-devel hdf5-devel sqlite-devel libspatialite-devel qt6-qtsvg-devel spatialindex-devel expat-devel netcdf-devel proj-devel qwt-qt6-devel gsl-devel PDAL PDAL-devel postgresql-devel cmake python3-gdal gdal-python-tools python3-psycopg2 python3-PyYAML python3-pygments python3-jinja2 python3-OWSLib qca-qt6-ossl qwt-qt6-devel qtkeychain-qt6-devel libzip-devel exiv2-devel PyQt-builder protobuf-lite protobuf-lite-devel libzstd-devel qt6-qtserialport-devel draco-devel python3-devel qt6-qt5compat-devel python3-pyqt6-webengine

# 构建 QGIS Server
dnf install fcgi-devel

# 构建 QGIS Server landing page
dnf install nodejs yarnpkg

# QGIS 开发（如源码格式化、测试等）
dnf install ag ccache expect ninja-build astyle python3-autopep8 python3-mock python3-nose2 perl-YAML-Tiny

# 配置编译参数
rm -rf /data/QGIS/build \& rm -rf ~/apps \& mkdir -p /data/QGIS/build \& mkdir -p ~/apps \& cd /data/QGIS/build/
ccmake .. -G Ninja -DBUILD\_WITH\_QT6=ON -DWITH\_QTWEBKIT=OFF -DWITH\_QTWEBENGINE=ON -DCMAKE\_INSTALL\_PREFIX=~/apps

# 编译项目
ninja -j5

# 安装到系统
ninja install

# 手动指定共享库路径（安装路径（~/apps）不在系统默认的共享库搜索路径中，导致程序运行时无法定位到依赖的库文件。）
vim ~/.bashrc

if [ -z "$LD_LIBRARY_PATH" ]; then
    export LD_LIBRARY_PATH="$HOME/apps/lib"
else
    export LD_LIBRARY_PATH="$HOME/apps/lib:$LD_LIBRARY_PATH"
fi

source ~/.bashrc

# WSL2 系统导出与导入
wsl --terminate Ubuntu-24.04
wsl --unregister Ubuntu-24.04

wsl --terminate FedoraLinux-42
wsl --unregister FedoraLinux-42
wsl --export FedoraLinux-42 D:\wsl-exports\FedoraLinux42.tar
wsl --import FedoraLinux-42 C:\ProgramFiles\WslSystems\FedoraLinux-42 D:\wsl-exports\FedoraLinux42.tar --version 2
wsl -d FedoraLinux-42
wsl --set-default FedoraLinux-42


