import Main from '@/page/Main';
import Login from '@/page/auth/login';
import Register from '@/page/auth/register';
import { ApiProvider } from '@/provider/ApiContainerProvider';
import { createBrowserRouter } from 'react-router-dom';

const routes = createBrowserRouter([
  {
    path: '',
    element: <ApiProvider />,
    children: [
      {
        path: '',
        element: <Main />,
      },
      {
        path: 'login',
        element: <Login />,
      },
      {
        path: 'register',
        element: <Register />,
      },
    ],
  },
]);

export default routes;
