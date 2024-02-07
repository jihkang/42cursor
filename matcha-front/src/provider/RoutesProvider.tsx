import { RouterProvider } from 'react-router-dom';
import routes from '@/router/routes';

const RouteProviders = () => {
  return (
    <>
      <RouterProvider router={routes} />
    </>
  );
};

export default RouteProviders;
